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
	SY = 0;
	Spawnersleft = true;
}

// Called when the game starts or when spawned
void ANPCManager::BeginPlay()
{
	Super::BeginPlay();
	ANPC* NPC = Cast<ANPC>(this);
	UWorld* world = GetWorld();
	//FindAllActors(world, spawnerArray);
}

// Called every frame
void ANPCManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//if (Spawnersleft == true)
	//{
	//	SetSpawner();
	//}

}

void ANPCManager::SetSpawner()
{
	//RanNumMaker();
	//float Y = float(RNum);
	//CurrentSpawner = TotalSpawners[SY];
	//if (CurrentSpawner && CurrentSpawner->Used == false)
	//{
	//	if (CurrentSpawner->SpawnNow == true) 
	//	{
	//		CurrentSpawner->ToSpawn = NPCType;
	//		CurrentSpawner->XNPC = Y;
	//	}
	//	else
	//	{
	//		CurrentSpawner->Used = true;
	//		SY++;
	//		if (SY == TotalSpawners.Num()){Spawnersleft = false;}
	//		
	//	}
	//}
}

void ANPCManager::SetLevel(int level)
{
	currentLevel = level;
}

int* ANPCManager::GetLevel()
{
	return &currentLevel;
}

int ANPCManager::RanNumMaker()
{
	RNum = FMath::RandRange(1, 5);
	return RNum;
}