// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_MainMenu.h"
#include "Components/Button.h"
#include "MMPlayerController.h"
#include "UI_InstructPanel.h"
#include "GameFramework/Controller.h"
#include "Kismet/GameplayStatics.h"

bool UUI_MainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	//If statements for adding in a button. 
		if (PlayButton)
		{
		    if (GEngine)
		        GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "Found play button");
		    PlayButton->OnClicked.AddDynamic(this, &UUI_MainMenu::OnClickEvent);
		}
		else
		{
		    if (GEngine)
		        GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "could not find play button");
		}


		if (QuitButton)
		{
			QuitButton->OnClicked.AddDynamic(this, &UUI_MainMenu::OnClickQuitEvent);
		}

		if (InstructionsButton)
		{
			InstructionsButton->OnClicked.AddDynamic(this, &UUI_MainMenu::OnClickInstructionEvent);
		}

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "Running a widget in code");

	return true;
}

void UUI_MainMenu::OnClickEvent()
{
	UGameplayStatics::OpenLevel(this, "Floor1", false);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "I've Been clicked!");

}

void UUI_MainMenu::OnClickQuitEvent()
{
	GetOwningPlayer()->ConsoleCommand("quit");

}

void UUI_MainMenu::OnClickInstructionEvent()
{

	if (ClickTrue == false)
	{
		UIInstructPanel1->SetVisibility(ESlateVisibility::Visible);
		ClickTrue = true;
		return;
	}
	else
	{
		UIInstructPanel1->SetVisibility(ESlateVisibility::Hidden);
		ClickTrue = false;
		return;
	}
}
