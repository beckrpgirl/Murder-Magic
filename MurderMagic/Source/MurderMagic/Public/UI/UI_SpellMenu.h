// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Spell.h"
#include "MagiBolt.h"
#include "WindSurge.h"
#include "MageBlast.h"
#include "BurningHands.h"
#include "LightningStrikes.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpellManager.h"
#include "UI_SpellMenu.generated.h"

/**
 * 
 */


UCLASS()
class MURDERMAGIC_API UUI_SpellMenu : public UUserWidget
{
private:
	GENERATED_BODY()

	int SpellRank;

public:
	virtual bool Initialize() override;

	UFUNCTION(BlueprintPure, Category = "LevelNumber")
	FText LevelNumber();

	UFUNCTION(BlueprintPure, Category = "AbilityPointNumber")
	FString APNumber();

	UFUNCTION(BlueprintPure, Category = "SpellPower")
		FString APPowerOne();
	UFUNCTION(BlueprintPure, Category = "SpellPower")
		FString APPowerTwo();
	UFUNCTION(BlueprintPure, Category = "SpellPower")
		FString APPowerThree();
	UFUNCTION(BlueprintPure, Category = "SpellPower")
		FString APPowerFour();
	UFUNCTION(BlueprintPure, Category = "SpellPower")
		FString APPowerFive();

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell1Plus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell2Plus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell3Plus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell4Plus;

	UPROPERTY(meta = (BindWidget))
		class UButton* Button_Spell5Plus;

	UPROPERTY(meta = (BindWidget))
		class UButton* LockOne;

	UPROPERTY(meta = (BindWidget))
		class UButton* LockTwo;

	UPROPERTY(meta = (BindWidget))
		class UButton* LockThree;

	UFUNCTION()
		void OnClickEventOnePlus();

	UFUNCTION()
		void OnClickEventTwoPlus();

	UFUNCTION()
		void OnClickEventThreePlus();

	UFUNCTION()
		void OnClickEventFourPlus();

	UFUNCTION()
		void OnClickEventFivePlus();

	UFUNCTION()
		void OnClickEventlockOne();

	UFUNCTION()
		void OnClickEventlockTwo();

	UFUNCTION()
		void OnClickEventlockThree();

private:

	void APAdditionCheck(FName BName);
	void APUnlock(FName BName);
	void CheckVisability();


	float SPower;
	bool Unlock;
	int SpellOne;
	int SpellTwo;
	int SpellThree;
	int SpellFour;
	int SpellFive;

	FTimerHandle MenuCheck;

};
