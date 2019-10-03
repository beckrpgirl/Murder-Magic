// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TriggerManager.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_TriggerCount.generated.h"

/**
 * 
 */

UCLASS()
class MURDERMAGIC_API UUI_TriggerCount : public UUserWidget
{
	GENERATED_BODY()

		virtual bool Initialize() override;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<AActor*> TMArray;

	ATriggerManager* TM;
	

	UFUNCTION(BlueprintPure, Category = "triggers")
	FString TriggerInfo();

};
