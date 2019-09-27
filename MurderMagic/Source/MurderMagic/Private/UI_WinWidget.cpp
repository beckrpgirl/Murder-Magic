// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_WinWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

bool UUI_WinWidget::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	//If statements for adding in a button. 
	if (MainMenuButton)
	{
		MainMenuButton->OnClicked.AddDynamic(this, &UUI_WinWidget::OnClickEventMM);
	}
	if (PlayButton)
	{
		PlayButton->OnClicked.AddDynamic(this, &UUI_WinWidget::OnClickEventPlay);
	}
	else
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "could not find play button");
	}

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "Running a widget in code");

	return true;

}

void UUI_WinWidget::OnClickEventPlay()
{
	UGameplayStatics::OpenLevel(this, "Floor1", false);
}

void UUI_WinWidget::OnClickEventMM()
{
	UGameplayStatics::OpenLevel(this, "MainMenu", false);
}
