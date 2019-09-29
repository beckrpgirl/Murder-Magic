// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBar.generated.h"


class AMurderMagicCharacter;

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UHealthBar : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Health")
	float UpdateHealthPercent();

	UPROPERTY(BlueprintReadWrite)
	AMurderMagicCharacter* Character;
	
};
