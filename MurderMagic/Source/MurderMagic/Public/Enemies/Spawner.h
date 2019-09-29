// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "NPC.h"
#include "Engine/EngineTypes.h"
#include "Spawner.generated.h"

UCLASS()
class MURDERMAGIC_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner(const FObjectInitializer& OI);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleDefaultsOnly)
		UBoxComponent* CollisionBox;

	//three different classes can be set to spawn from one point.
	UPROPERTY(EditAnywhere, Category = SpawnSettings)
		TSubclassOf<class ANPC> ToSpawn_1;
	UPROPERTY(EditAnywhere, Category = SpawnSettings)
		TSubclassOf<class ANPC> ToSpawn_2;
	UPROPERTY(EditAnywhere, Category = SpawnSettings)
		TSubclassOf<class ANPC> ToSpawn_3;
	//Max and Min setting for number of spawns to be produced.
	UPROPERTY(EditAnywhere, Category = SpawnSettings)
		int Max;
	UPROPERTY(EditAnywhere, Category = SpawnSettings)
		int Min;
	//TimeDelay in spawns.
	UPROPERTY(EditAnywhere, Category = SpawnSettings)
		float TimeDelay;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);
	UFUNCTION()
		virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	float i;
	int K;
	void SpawnDelay();
	void RandomNPC();

	bool SpawnNow;
	bool Used;
	float XNPC;
	int RandomNumber();
	int RNum;

	FVector Location;
	FRotator Rotation;

	FTimerHandle _TimerHandle;
};
