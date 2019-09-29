// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API AGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	AGameHUD();

	UPROPERTY(EditDefaultsOnly)
	class UClass* hudWidgetClass;
	UPROPERTY(EditDefaultsOnly)
	class UClass* hudWidgetMMClass;
	UPROPERTY(EditDefaultsOnly)
	class UClass* hudWidgetWSClass;

	class UUserWidget* hudWidget;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "TestFunctions")
	FString GetCurrentMapName();

	FString CurrentMapName;
	UWorld* MyWorld;
	
};
