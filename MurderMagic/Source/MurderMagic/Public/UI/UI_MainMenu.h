// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_InstructPanel.h"
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

	UPROPERTY(meta = (BindWidget))
		class UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* InstructionsButton;

	UPROPERTY(meta = (BindWidget))
		class UUserWidget* UIInstructPanel1;

	UFUNCTION()
		void OnClickEvent();

	UFUNCTION()
		void OnClickQuitEvent();

	UFUNCTION()
		void OnClickInstructionEvent();

	bool ClickTrue = false;

};
