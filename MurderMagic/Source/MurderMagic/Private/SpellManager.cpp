// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellManager.h"
#include "MagiBolt.h"

// Sets default values
ASpellManager::ASpellManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpellManager::BeginPlay()
{
	Super::BeginPlay();

	equippedSpellL = (ASpell *)GetWorld()->SpawnActor(AMagiBolt::StaticClass());
	equippedSpellR = equippedSpellL;
	
}

// Called every frame
void ASpellManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpellManager::NextSpellL()
{
	equippedSpellL = equippedSpellL->next;
}

void ASpellManager::NextSpellR()
{
	equippedSpellR = equippedSpellR->next;
}

void ASpellManager::CastSpellL(FVector start, float angle)
{
	//When you click into the game to start moving it tries to pull this infor and crashes. 
//	equippedSpellL->Cast(start, angle);
}

void ASpellManager::CastSpellR(FVector start, float angle)
{
	equippedSpellR->Cast(start, angle);
}