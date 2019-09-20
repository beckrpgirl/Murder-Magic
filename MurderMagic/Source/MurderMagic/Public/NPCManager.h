// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Templates.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "AITargetPoint.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPC.h"
#include "Spawner.h"
#include "NPCManager.generated.h"

UCLASS()
class MURDERMAGIC_API ANPCManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANPCManager();

	UPROPERTY(EditAnywhere, Category = Reference, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<ANPC> GoblinRef;
	UPROPERTY(EditAnywhere, Category = Reference, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<ANPC> OgreRef;
	UPROPERTY(EditAnywhere, Category = Reference, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<ANPC> BossRef;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AAITargetPoint> spawners;

	TArray<AAITargetPoint*> spawnerArray;
	AAITargetPoint* currentSpawner;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
