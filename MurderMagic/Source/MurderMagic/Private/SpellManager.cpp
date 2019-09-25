// Fill out your copyright notice in the Description page of Project Settings.

#include "SpellManager.h"

// Sets default values
ASpellManager::ASpellManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
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
	
	equippedSpellL = Cast<ASpell>(GetWorld()->SpawnActor(AMagiBolt::StaticClass()));
	equippedSpellR = equippedSpellL;
	hasLeftUpdated = true;
}

// Called every frame
void ASpellManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (hasLeftUpdated)
	{
		spellSlotRef->UpdateLeftSlotImage(equippedSpellL->SpellTexture);
		hasLeftUpdated = false;
	}
	if (hasRightUpdated)
	{
		spellSlotRef->UpdateRightSlotImage(equippedSpellR->SpellTexture);
		hasRightUpdated = false;
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