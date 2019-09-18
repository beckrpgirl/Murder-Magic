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

	MaxHealth = 100;
	Health = MaxHealth;

	ExperienceToNextLevel = 100;

	MaxMana = 100;
	ManaRegen = 3;
	Mana = MaxMana;
}

//////////////////////////////////////////////////////////////////////////
// Input

void AMurderMagicCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMurderMagicCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMurderMagicCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMurderMagicCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMurderMagicCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AMurderMagicCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AMurderMagicCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AMurderMagicCharacter::OnResetVR);

	//Binding the new player actions to their specific key presses set in UE4
	PlayerInputComponent->BindAction("QuitGame", IE_Pressed, this, &AMurderMagicCharacter::ExitGame);
	PlayerInputComponent->BindAction("LeftAbility", IE_Pressed, this, &AMurderMagicCharacter::FireLeftAbility);
	PlayerInputComponent->BindAction("RightAbility", IE_Pressed, this, &AMurderMagicCharacter::FireRightAbility);
	PlayerInputComponent->BindAction("ObjectInteract", IE_Pressed, this, &AMurderMagicCharacter::ObjectInteract);
	PlayerInputComponent->BindAction("SwitchLeftAbility", IE_Pressed, this, &AMurderMagicCharacter::CycleLeftAbility);
	PlayerInputComponent->BindAction("SwitchRightAbility", IE_Pressed, this, &AMurderMagicCharacter::CycleRightAbility);


}


void AMurderMagicCharacter::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(AddMana_Handler, this, &AMurderMagicCharacter::RegenMana, 1, true);

	APlayerController* PC = Cast<APlayerController>(GetController());

	if (PC)
	{
		PC->bShowMouseCursor = true;
		PC->bEnableClickEvents = true;
		PC->bEnableMouseOverEvents = true;
	}

	UMMGameInstance* GI = Cast<UMMGameInstance>(GetGameInstance());
	Experience = GI->PlayerXP;
	Health = GI->PlayerHealth;
	Mana = GI->PlayerMana;

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

	if (Mana != MaxMana) {

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

void AMurderMagicCharacter::OnOverlapBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{

	Collectibles = Cast<ACollectibleParent>(OtherActor);

	if (OtherActor && (OtherActor != this) && OtherComp) {

		if (GEngine) {

			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "did overlap");
		}

	}

	if (OtherActor == Collectibles) {

		Collectibles->OnInteract(this);

	}

}

void AMurderMagicCharacter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{



}

void AMurderMagicCharacter::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AMurderMagicCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AMurderMagicCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AMurderMagicCharacter::ExitGame()
{

	if (GetController()) {

		Cast<APlayerController>(GetController())->ConsoleCommand("quit");

	}

}

void AMurderMagicCharacter::FireLeftAbility()
{
}

void AMurderMagicCharacter::FireRightAbility()
{
}

void AMurderMagicCharacter::ObjectInteract()
{
}

void AMurderMagicCharacter::CycleLeftAbility()
{
}

void AMurderMagicCharacter::CycleRightAbility()
{
}

void AMurderMagicCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMurderMagicCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMurderMagicCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMurderMagicCharacter::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
