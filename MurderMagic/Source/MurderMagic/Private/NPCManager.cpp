// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCManager.h"

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
	FindAllActors(world, spawnerArray);
}

// Called every frame
void ANPCManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (int i = 0; i < spawnerArray.Num(); i++)
	{
		currentSpawner = Cast<AAITargetPoint>(spawnerArray[i]);
		if (currentSpawner->SpawnNow)
		{
			currentSpawner->SpawnEnemies(5, 1, GoblinRef, OgreRef, BossRef);
		}
	}
}

