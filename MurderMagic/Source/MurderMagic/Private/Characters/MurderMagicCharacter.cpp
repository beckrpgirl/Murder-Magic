// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MurderMagicCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "CollectibleParent.h"
#include "MMGameInstance.h"
#include "Trigger.h"
#include "MMPlayerController.h"
#include "NPC.h"

//////////////////////////////////////////////////////////////////////////
// AMurderMagicCharacter

AMurderMagicCharacter::AMurderMagicCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("TriggerCapsule"));
	TriggerCapsule->InitCapsuleSize(42.f, 96.0f);
	TriggerCapsule->SetCollisionProfileName(TEXT("Trigger"));
	TriggerCapsule->SetupAttachment(RootComponent);
	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &AMurderMagicCharacter::OnOverlapBegin);
	TriggerCapsule->OnComponentEndOverlap.AddDynamic(this, &AMurderMagicCharacter::OnOverlapEnd);

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
	ManaRegen = 3;
	TriggersCollected = 0;

}


void AMurderMagicCharacter::BeginPlay()
{
	Super::BeginPlay();
	//timer for Mana
	GetWorld()->GetTimerManager().SetTimer(AddMana_Handler, this, &AMurderMagicCharacter::RegenMana, 1, true);

	APlayerController* PC = Cast<APlayerController>(GetController());
	UMMGameInstance* GI = Cast<UMMGameInstance>(GetGameInstance());

	//setting player info according to what's stored on the Game Instance
	Experience = GI->PlayerXP;
	CurrentPlayerLevel = GI->PlayerLvl;
	SetPlayerStats();
	currentAP = GI->PlayerAP;

	//mouse showing
	if (PC)
	{
		PC->bShowMouseCursor = true;
		PC->bEnableClickEvents = true;
		PC->bEnableMouseOverEvents = true;
	}
}

bool AMurderMagicCharacter::AddHealth(float Points)
{
	
	Health += Points;

	if (Health > MaxHealth) {

		Health = MaxHealth;

	}

	return true;

}

void AMurderMagicCharacter::RegenMana()
{

	if (Mana < MaxMana) {

		Mana += ManaRegen;

	}


	if (Mana > MaxMana) {

		Mana = MaxMana;

	}

}

bool AMurderMagicCharacter::UseMana(float Points)
{
	
	Mana -= Points;

	if (Mana <= 0) {

		Mana = 0;

	}

	return true;

}

bool AMurderMagicCharacter::AddMana(float Points)
{
	Mana += Points;

	if (Mana > MaxMana) {

		Mana = MaxMana;

	}

	return true;
}

bool AMurderMagicCharacter::AddExperience(float Points)
{
	Experience += Points;

	return true;
}

int AMurderMagicCharacter::GetCurrentPlayerLevel()
{
	return CurrentPlayerLevel;
}

float AMurderMagicCharacter::GetManaPercent()
{
	return Mana / MaxMana;
}

float AMurderMagicCharacter::GetHealthPercent()
{
	return Health / MaxHealth;
}

float AMurderMagicCharacter::GetExperiencePercent()
{
	return Experience / ExperienceToNextLevel;
}

float AMurderMagicCharacter::GetExperience()
{
	return Experience;
}

float AMurderMagicCharacter::GetMaxExperience()
{
	return ExperienceToNextLevel;
}

float AMurderMagicCharacter::GetCurrentMana()
{
	return Mana;
}

int AMurderMagicCharacter::GetTriggersCollected()
{
	return TriggersCollected;
}

void AMurderMagicCharacter::AddTriggersCollected()
{
	TriggersCollected += 1;
}

void AMurderMagicCharacter::PlayerLevelup()
{

	if (Experience >= ExperienceToNextLevel) {

		CurrentPlayerLevel++;
		SetPlayerStats();
		Experience = 0;

		if (GEngine) {

			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "AP: " + FString::FromInt(currentAP));
		}

	}

	if (CurrentPlayerLevel == 10) {

		Experience = 0;

	}

}

void AMurderMagicCharacter::SetPlayerStats()
{

	if (DataTable) {

		Row = DataTable->FindRow<FDataTableStruct>(FName(*FString::FromInt(CurrentPlayerLevel)), TEXT(""));

		if (Row)
		{
			MaxHealth = Row->MaxHealth;
			Health = MaxHealth;
			currentAP = currentAP + Row->AbilityPoint;
			ExperienceToNextLevel = Row->ExperienceToNextLevel;

			MaxMana = Row->MaxMana;
			Mana = MaxMana;
		}
	}

}

void AMurderMagicCharacter::SubtractAP()
{
	currentAP = currentAP - 1;
}

int AMurderMagicCharacter::GetTotalAP()
{
	int AP = CurrentPlayerLevel - 1;
	return AP;
}

void AMurderMagicCharacter::OnOverlapBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	ACollectibleParent *TempCollectibles = Cast<ACollectibleParent>(OtherActor);
	ATrigger *TempTrig = Cast<ATrigger>(OtherActor);
	ANPC *NPC = Cast<ANPC>(OtherActor);
	if (TempTrig) {
		Triggers = TempTrig;
	}

	if (TempCollectibles) {
		Collectibles = TempCollectibles;
	}

	if (OtherActor && (OtherActor != this) && OtherComp) {
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "did overlap");
	}

	if (OtherActor == Collectibles) {
		Collectibles->OnInteract(this);
		PlayerLevelup();
	}

	
	if (NPC)
	{
		if (GetHealthPercent() <= 0.2)
		{
			Health -= (NPC->GetDamage() / 1.5);
		}
		else
		{
			Health -= NPC->GetDamage();
		}
		NPC->Destroy();
	}

}

void AMurderMagicCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == Triggers) {

		Triggers = nullptr;
	}
}
