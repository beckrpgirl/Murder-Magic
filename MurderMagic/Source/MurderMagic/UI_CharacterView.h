// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_CharacterView.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UUI_CharacterView : public UUserWidget
{
	GENERATED_BODY()
	
		virtual bool Initialize() override;

	//UPROPERTY(meta = (BindWidget))
	//	class UButton* PlayButton;

	//UPROPERTY(meta = (BindWidget))
	//	class UQuestBoardBase* UI_QuestBoard;

	//UPROPERTY(meta = (BindWidget))
	//	class UUI_QuestGiverBase* UI_QuestGiver;

	//UFUNCTION()
	//	void OnClickEvent();

	

};
