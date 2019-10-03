// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "NPC.h"
#include "Engine/EngineTypes.h"
#include "Spawner.generated.h"

class ATargetPoint;

USTRUCT()
struct FSpawnData
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = SpawnData)
	TSubclassOf<class ANPC> unit;
	UPROPERTY(EditAnywhere, Category = SpawnData)
	int MinCount;
	UPROPERTY(EditAnywhere, Category = SpawnData)
	int MaxCount;
};

UCLASS()
class MURDERMAGIC_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner(const FObjectInitializer& OI);

private:
	UPROPERTY(VisibleDefaultsOnly)
	UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere, Category = "Spawner|SpawnData")
	TArray<FSpawnData> UnitSpawnData;

	UPROPERTY(EditAnywhere, Category = "Spawner|SpawnZones")
	TArray<ATargetPoint*> SpawnZones;
	//Max and Min setting for number of spawns to be produced.
	UPROPERTY(EditAnywhere, Category = "Spawner|SpawnZones")
	int SpawnMaxDistance;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

	void SpawnWave();
};
