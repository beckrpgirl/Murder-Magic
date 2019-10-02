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
#include "UI_SpellMenu.generated.h"

/**
 * 
 */


UCLASS()
class MURDERMAGIC_API UUI_SpellMenu : public UUserWidget
{
private:
	GENERATED_BODY()

	ASpell* MagiBoltSpell;
	ASpell* WindSurgeSpell;
	ASpell* MageBlastSpell;
	ASpell* BurningHandsSpell;
	ASpell* LightningStrikesSpell;

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

	//Spell details
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ASpell> MagiBoltBP;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ASpell> WindSurgeBP;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ASpell> MageBlastBP;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ASpell> BurningHandsBP;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ASpell> LightningStrikesBP;


private:

	void APRemovalCheck();
	void APAdditionCheck();
	float APPowerCount();

	float SPower;

};
