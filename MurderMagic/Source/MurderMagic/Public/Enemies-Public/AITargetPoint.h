// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "NPC.h"
#include "T1_Goblin.h"
#include "T2_Ogre.h"
#include "T3_Boss.h"
#include "MurderMagicCharacter.h"
#include "CoreMinimal.h"
#include "Engine/TargetPoint.h"
#include "AITargetPoint.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API AAITargetPoint : public ATargetPoint
{
	GENERATED_BODY()
	
public:

	AMurderMagicCharacter* Pawn;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void SpawnEnemies(int amount, int tier, TSubclassOf<ANPC> GoblinRef, TSubclassOf<ANPC> OgreRef, TSubclassOf<ANPC> BossRef);
	bool SpawnNow = false;
};
