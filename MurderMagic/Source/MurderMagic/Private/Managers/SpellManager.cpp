// Fill out your copyright notice in the Description page of Project Settings.

#include "SpellManager.h"
#include "MMGameInstance.h"

// Sets default values
ASpellManager::ASpellManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FClassFinder<UUserWidget> BlueprintClass(TEXT("WidgetBlueprint'/Game/ThirdPersonCPP/UI/UI_SpellSlots'"));
	if (BlueprintClass.Class)
		spellSlotRefClass = BlueprintClass.Class;
}

ASpell* ASpellManager::GetLeftSpell()
{
	return equippedSpellL;
}

ASpell* ASpellManager::GetRightSpell()
{
	return equippedSpellR;
}

// Called when the game starts or when spawned
void ASpellManager::BeginPlay()
{
	Super::BeginPlay();
	
	// Spawning all the spells for the manager to control and put them in the slots
	if (spellSlotRefClass)
	{
		spellSlotRef = CreateWidget<USpellSlots>(GetWorld()->GetFirstPlayerController(), spellSlotRefClass);
	}
	MagiBoltSpell = Cast<ASpell>(GetWorld()->SpawnActor(MagiBoltBP));
	WindSurgeSpell = Cast<ASpell>(GetWorld()->SpawnActor(WindSurgeBP));
	MageBlastSpell = Cast<ASpell>(GetWorld()->SpawnActor(MageBlastBP));
	BurningHandsSpell = Cast<ASpell>(GetWorld()->SpawnActor(BurningHandsBP));
	LightningStrikesSpell = Cast<ASpell>(GetWorld()->SpawnActor(LightningStrikesBP));

	MagiBoltSpell->next = WindSurgeSpell;
	WindSurgeSpell->next = MageBlastSpell;
	MageBlastSpell->next = BurningHandsSpell;
	BurningHandsSpell->next = LightningStrikesSpell;
	LightningStrikesSpell->next = MagiBoltSpell;

	// Setting the starting spells
	equippedSpellL = MagiBoltSpell;
	equippedSpellR = WindSurgeSpell;
	hasLeftUpdated = true;
	hasRightUpdated = true;

	//Getting Spell Values
	UMMGameInstance* GI = Cast<UMMGameInstance>(GetGameInstance());
	if (GI)
	{
		MagiBoltSpell->isUnlocked = GI->MagiBoltUnlocked;
		MagiBoltSpell->SetAPBonus(GI->MagiBoltAP);
		WindSurgeSpell->isUnlocked = GI->WindSurgeUnlocked;
		GI->WindSurgeAP;
		MageBlastSpell->isUnlocked = GI->MageBlastUnlocked;
		GI->MageBlastAP;
		BurningHandsSpell->isUnlocked = GI->BurningHandsUnlocked;
		GI->BurningHandsAP;
		LightningStrikesSpell->isUnlocked = GI->LightingStrikesUnlocked;
		GI->LightingStrikesAP;
	}
}

// Called every frame
void ASpellManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (hasLeftUpdated)
	{
		spellSlotRef->UpdateLeftSlotImage();
		hasLeftUpdated = false;
	}
	if (hasRightUpdated)
	{
		spellSlotRef->UpdateRightSlotImage();
		hasRightUpdated = false;
	}
}

void ASpellManager::NextSpellL()
{
	equippedSpellL = equippedSpellL->next;
	if (!equippedSpellL->isUnlocked)
	{
		NextSpellL();
	}
	hasLeftUpdated = true;
}

void ASpellManager::NextSpellR()
{
	equippedSpellR = equippedSpellR->next;
	if (!equippedSpellR->isUnlocked)
	{
		NextSpellR();
	}
	hasRightUpdated = true;
}

void ASpellManager::CastSpellL(FVector start, FVector facingDirection, float angle)
{
	equippedSpellL->CastSpell(start, facingDirection, angle);
}

void ASpellManager::CastSpellR(FVector start, FVector facingDirection, float angle)
{
	equippedSpellR->CastSpell(start, facingDirection, angle);
}

ASpell* ASpellManager::GetMagiBolt()
{
	return MagiBoltSpell;
}

ASpell* ASpellManager::GetWindSurge()
{
	return WindSurgeSpell;
}

ASpell* ASpellManager::GetMageBlast()
{
	return MageBlastSpell;
}

ASpell* ASpellManager::GetBurningHands()
{
	return BurningHandsSpell;
}

ASpell* ASpellManager::GetLightningStrikes()
{
	return LightningStrikesSpell;
}



