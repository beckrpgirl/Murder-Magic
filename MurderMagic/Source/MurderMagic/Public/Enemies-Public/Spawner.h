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

	UPROPERTY(EditAnywhere)
		TSubclassOf<class ANPC> ToSpawn;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);
	UFUNCTION()
		virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
	UPROPERTY(EditAnywhere)
	float XNPC = 5;

	float i;
	void SpawnDelay();
	void EndTimer();

	bool SpawnNow;
	bool Used;

	FVector Location;
	FRotator Rotation;

	FTimerHandle _TimerHandle;
};
