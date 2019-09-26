// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPC.h"
#include "T1_Goblin.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API AT1_Goblin : public ANPC
{
	GENERATED_BODY()
	
	float MovementSpeed;
	float MaxHealth = 10;
	float Damage = 5;
	float AttackSpeed;
	int EXPWorth = 10;


};
