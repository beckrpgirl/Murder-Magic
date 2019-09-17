// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "XPBar.generated.h"


class AMurderMagicCharacter;
/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UXPBar : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "XP")
	float UpdateXPPercent();

	UPROPERTY(BlueprintReadWrite)
	AMurderMagicCharacter* Character;
	
};
