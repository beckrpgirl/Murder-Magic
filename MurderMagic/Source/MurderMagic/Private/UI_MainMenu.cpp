// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_MainMenu.h"

bool UUI_MainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	//If statements for adding in a button. 
		if (PlayButton)
		{
		    //if (GEngine)
		    //    GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "Found play button");
		  //  PlayButton->OnClicked.AddDynamic(this, &UUI_MainMenu::OnClickEvent);
		}
		else
		{
		    //if (GEngine)
		    //    GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "could not find play button");
		}

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "Running a widget in code");

	return true;
}

void UUI_MainMenu::OnClickEvent()
{

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "I've Been clicked!");


}
