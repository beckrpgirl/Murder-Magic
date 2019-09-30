// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_SpellMenu.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UUI_SpellMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

	UFUNCTION(BlueprintPure, Category = "LevelNumber")
		FString LevelNumber();

		FString CLevel;

	UFUNCTION(BlueprintPure, Category = "AbilityPointNumber")
		FString APNum();

	FString CAP;

	

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell1Plus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell1Minus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell2Plus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell2Minus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell3Plus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell3Minus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell4Plus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell4Minus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell5Plus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell5Minus;

	UPROPERTY(meta = (BindWidget))
		class UButton* ResumeButton;


	UFUNCTION()
		void OnClickEventOnePlus();

	UFUNCTION()
		void OnClickEventOneMinus();

	UFUNCTION()
		void OnClickEventTwoPlus();

	UFUNCTION()
		void OnClickEventTwoMinus();

	UFUNCTION()
		void OnClickEventThreePlus();

	UFUNCTION()
		void OnClickEventThreeMinus();

	UFUNCTION()
		void OnClickEventFourPlus();

	UFUNCTION()
		void OnClickEventFourMinus();

	UFUNCTION()
		void OnClickEventFivePlus();

	UFUNCTION()
		void OnClickEventFiveMinus();

	UFUNCTION()
		void OnClickEventResumeButton();

	bool ClickResumeTrue = false;

};
