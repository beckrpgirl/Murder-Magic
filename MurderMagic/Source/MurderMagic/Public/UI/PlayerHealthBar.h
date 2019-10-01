// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/HealthBar.h"
#include "PlayerHealthBar.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UPlayerHealthBar : public UHealthBar
{
private:

	GENERATED_BODY()
	
public:

	virtual float UpdateHealthPercent() override;
};
