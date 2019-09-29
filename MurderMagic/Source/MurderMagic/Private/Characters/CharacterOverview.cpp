// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterOverview.h"
#include "Components/Button.h"
#include "UserWidget.h"
#include "Kismet/GameplayStatics.h"

bool UCharacterOverview::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	//If statements for adding in a button. 
		if (SpellMenu)
		{
		   
		    SpellMenu->OnClicked.AddDynamic(this, &UCharacterOverview::OnClickEvent);
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

void UCharacterOverview::OnClickEvent()
{

	if (ClickTrue == false)
	{
		UISpellMenu->SetVisibility(ESlateVisibility::Visible);
		ClickTrue = true;
		return;
	}
	else
	{
		UISpellMenu->SetVisibility(ESlateVisibility::Hidden);
		ClickTrue = false;
		return;
	}
}
