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
	class UUserWidget* hudWidget;

	virtual void BeginPlay() override;
	
};
