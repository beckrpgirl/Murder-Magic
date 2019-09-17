// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "MurderMagicCharacter.h"

// Sets default values
ALevelManager::ALevelManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ALevelManager::SetLevelManager()
{
	AMurderMagicCharacter* PC = Cast<AMurderMagicCharacter>(this);

	if (PC)
	{
		PC->CurrentLevelManager = this;
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "Current Level Manager level info Loaded");

	}
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "Fail to load Level Manager level info");



}

// Called when the game starts or when spawned
void ALevelManager::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentLvlMapInfo = LevelMapInformation[0];

	SetLevelManager();

}

// Called every frame
void ALevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelManager::GetLevelInfo()
{



}

