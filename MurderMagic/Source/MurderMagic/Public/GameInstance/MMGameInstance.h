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

	//Player values
	float PlayerHealth;
	float PlayerMana;
	float PlayerXP;
	float PlayerMaxXP;
	int PlayerLvl;
	FTransform PlayerLocation;



};
