// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI_InstructPanel.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UUI_InstructPanel : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

	UPROPERTY(meta = (BindWidget))
		class UButton* InstructExitButton;

	UFUNCTION()
		void OnClickInstructExitEvent();

	bool ClickTrue = false;

	
};
