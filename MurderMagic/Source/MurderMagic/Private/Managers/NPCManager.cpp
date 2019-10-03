// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCManager.h"
#include "Spawner.h"
#include "NPC.h"
#include "UnrealMathUtility.h"

// Sets default values
ANPCManager::ANPCManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ANPCManager::BeginPlay()
{
	Super::BeginPlay();
	UWorld* world = GetWorld();
}

// Called every frame
void ANPCManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ANPCManager::SetLevel(int level)
{
	currentLevel = level;
}

int* ANPCManager::GetLevel()
{
	return &currentLevel;
}
