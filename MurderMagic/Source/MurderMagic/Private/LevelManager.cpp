// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "Templates.h"
#include "MurderMagicCharacter.h"


// Sets default values
ALevelManager::ALevelManager(const FObjectInitializer& OI)
	: Super(OI)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ALevelManager::SetLevelManager()
{
	
}

// Called when the game starts or when spawned
void ALevelManager::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentLvlMapInfo = LevelMapInformation[0];

	SetLevelManager();

	firstTick = true;

}

// Called every frame
void ALevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (firstTick)
	{
	

		firstTick = false;
	}

}

void ALevelManager::GetLevelInfo()
{



}

