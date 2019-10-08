// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_InstructPanel.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

bool UUI_InstructPanel::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (InstructExitButton)
	{
		InstructExitButton->OnClicked.AddDynamic(this, &UUI_InstructPanel::OnClickInstructExitEvent);
	}
	return true;
}

void UUI_InstructPanel::OnClickInstructExitEvent()
{
	
		this->SetVisibility(ESlateVisibility::Hidden);
		
		return;
}
