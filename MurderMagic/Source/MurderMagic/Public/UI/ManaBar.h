// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ManaBar.generated.h"


class AMurderMagicCharacter;
/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UManaBar : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Mana")
	float UpdateManaPercent();

	UPROPERTY(BlueprintReadWrite)
	AMurderMagicCharacter* Character;
	
};
