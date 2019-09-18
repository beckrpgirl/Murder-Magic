// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UUI_MainMenu : public UUserWidget
{
	GENERATED_BODY()

public:	
	virtual bool Initialize() override;

	UPROPERTY(meta = (BindWidget))
		class UButton* PlayButton;

	UFUNCTION()
		void OnClickEvent();

};
