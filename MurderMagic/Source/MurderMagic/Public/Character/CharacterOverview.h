// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_SpellMenu.h"
#include "CharacterOverview.generated.h"



/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UCharacterOverview : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize() override;

	UPROPERTY(meta = (BindWidget))
		class UButton* SpellMenu;

	UPROPERTY(meta = (BindWidget))
		class UUI_SpellMenu* UISpellMenu;

		UFUNCTION()
		void OnClickEvent();

		bool ClickTrue = false;

	
};
