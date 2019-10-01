// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_SpellMenu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "CharacterOverview.h"
#include "MurderMagicCharacter.h"

bool UUI_SpellMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	/*If statements for adding in a button.*/ 
	if (Button_Spell1Plus)
	{
		Button_Spell1Plus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventOnePlus);
	}
	if (Button_Spell1Minus)
	{
		Button_Spell1Minus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventOneMinus);
	}
	if (Button_Spell2Plus)
	{
		Button_Spell2Plus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventTwoPlus);
	}
	if (Button_Spell2Minus)
	{
		Button_Spell2Minus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventTwoMinus);
	}
	if (Button_Spell3Plus)
	{
		Button_Spell3Plus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventThreePlus);
	}
	if (Button_Spell3Minus)
	{
		Button_Spell3Minus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventThreeMinus);
	}
	if (Button_Spell4Plus)
	{
		Button_Spell4Plus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventFourPlus);
	}
	if (Button_Spell4Minus)
	{
		Button_Spell4Minus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventFourMinus);
	}
	if (Button_Spell5Plus)
	{
		Button_Spell5Plus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventFivePlus);
	}
	if (Button_Spell5Minus)
	{
		Button_Spell5Minus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventFiveMinus);
	}

	if (ResumeButton)
	{
		ResumeButton->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventResumeButton);
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



FText UUI_SpellMenu::LevelNumber()
{
	FText CLevel;
	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());
	if (MMC)
	{
		CLevel = FText::AsNumber(MMC->CurrentPlayerLevel);

	}
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "HELLLOOOOOO KITTEN");

	return CLevel;

	
}

FString UUI_SpellMenu::APNumber()
{
	FString CAP = "0";
	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());
	if (MMC)
	{
		CAP = " " + FString::FromInt(MMC->currentAP);

	}

	return CAP;

}

void UUI_SpellMenu::OnClickEventOnePlus()
{
	APAdditionCheck();
}

void UUI_SpellMenu::OnClickEventOneMinus()
{
	APRemovalCheck();
}

void UUI_SpellMenu::OnClickEventTwoPlus()
{
	APAdditionCheck();
}

void UUI_SpellMenu::OnClickEventTwoMinus()
{
	APRemovalCheck();
}

void UUI_SpellMenu::OnClickEventThreePlus()
{
	APAdditionCheck();
}

void UUI_SpellMenu::OnClickEventThreeMinus()
{
	APRemovalCheck();
}

void UUI_SpellMenu::OnClickEventFourPlus()
{
	APAdditionCheck();
}

void UUI_SpellMenu::OnClickEventFourMinus()
{
	APRemovalCheck();
}

void UUI_SpellMenu::OnClickEventFivePlus()
{
	APAdditionCheck();
}

void UUI_SpellMenu::OnClickEventFiveMinus()
{
	APRemovalCheck();
}

void UUI_SpellMenu::OnClickEventResumeButton()
{

	if (ClickResumeTrue == false)
	{
		SetVisibility(ESlateVisibility::Hidden);
		ClickResumeTrue = true;
		return;
	}
	else
	{
		SetVisibility(ESlateVisibility::Visible);
		ClickResumeTrue = false;
		return;
	}
}
//Removal of AP from Spell
void UUI_SpellMenu::APRemovalCheck()
{
	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());
	if (MMC) {
		int TotalAP = MMC->GetTotalAP();
		int CurAP = MMC->currentAP;
		int SpellAP = TotalAP - CurAP; //something to add up all the AP spent on spells
		int DiffAP = TotalAP - SpellAP;

		if (CurAP < TotalAP)
		{
			MMC->AddAP();

			//something to do with subtracting to spell power, using the spell type passed through as a Something
		}

	}

}
//Adding AP to Spell
void UUI_SpellMenu::APAdditionCheck()
{
	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());
	if (MMC) {
		int CurAP = MMC->currentAP;
		if (CurAP >= 1)
		{
			MMC->SubtractAP();

			//something to do with adding to spell power, using the spell type passed through as a Something
		}

	}
}

