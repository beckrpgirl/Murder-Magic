// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/HealthBar.h"
#include "NPC.h"
#include "EnemyHealthBar.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UEnemyHealthBar : public UHealthBar
{
private:

	GENERATED_BODY()

	ANPC *Character;
	
public:

	virtual float UpdateHealthPercent() override;

	void SetCharacter(ANPC *npc);
};
