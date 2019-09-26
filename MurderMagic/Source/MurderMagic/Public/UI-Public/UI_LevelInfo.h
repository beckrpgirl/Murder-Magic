// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_LevelInfo.generated.h"

class AMurderMagicCharacter;
/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UUI_LevelInfo : public UUserWidget
{
	GENERATED_BODY()
	
		UFUNCTION(BlueprintPure, Category = "LevelInfo")
		FString CurrentLevel();

	FString CLevel;

	UFUNCTION(BlueprintPure, Category = "LevelInfo")
		FString CurrentFloor();

	FString CFloor;


};
