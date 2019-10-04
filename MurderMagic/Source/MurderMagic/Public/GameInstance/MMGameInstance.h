// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MMGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UMMGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	UMMGameInstance(const FObjectInitializer& ObjectInitializer);
public:

	//Player Values
	float PlayerXP;
	float PlayerMaxXP;
	int PlayerLvl;
	float PlayerAP;

	//Spell Values
	bool MagiBoltUnlocked = true;
	float MagiBoltAP;
	bool WindSurgeUnlocked = true;
	float WindSurgeAP;
	bool MageBlastUnlocked;
	float MageBlastAP;
	bool BurningHandsUnlocked;
	float BurningHandsAP;
	bool LightingStrikesUnlocked;
	float LightingStrikesAP;

};
