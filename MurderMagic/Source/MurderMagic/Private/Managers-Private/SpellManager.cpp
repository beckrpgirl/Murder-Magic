// Fill out your copyright notice in the Description page of Project Settings.

#include "SpellManager.h"

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

	// Setting the starting spells
	equippedSpellL = MagiBoltSpell;
	equippedSpellR = WindSurgeSpell;
	hasLeftUpdated = true;
	hasRightUpdated = true;
}

// Called every frame
void ASpellManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (hasLeftUpdated)
	{
		spellSlotRef->UpdateLeftSlotImage(equippedSpellL->SpellTexture);
		//hasLeftUpdated = false;
	}
	if (hasRightUpdated)
	{
		spellSlotRef->UpdateRightSlotImage(equippedSpellR->SpellTexture);
		//hasRightUpdated = false;
	}
}

void ASpellManager::NextSpellL()
{
	equippedSpellL = equippedSpellL->next;
	hasLeftUpdated = true;
}

void ASpellManager::NextSpellR()
{
	equippedSpellR = equippedSpellR->next;
	hasRightUpdated = true;
}

void ASpellManager::CastSpellL(FVector start, float angle)
{
	equippedSpellL->CastSpell(start, angle);
}

void ASpellManager::CastSpellR(FVector start, float angle)
{
	equippedSpellR->CastSpell(start, angle);
}

