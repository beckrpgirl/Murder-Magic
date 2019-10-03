// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_SpellMenu.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "CharacterOverview.h"
#include "MurderMagicCharacter.h"
#include "Spell.h"
#include "SpellManager.h"
#include "MagiBolt.h"
#include "WindSurge.h"
#include "MageBlast.h"
#include "BurningHands.h"
#include "LightningStrikes.h"

bool UUI_SpellMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	/*If statements for adding in a button.*/ 
	if (Button_Spell1Plus)
	{
		Button_Spell1Plus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventOnePlus);
	}
	if (Button_Spell2Plus)
	{
		Button_Spell2Plus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventTwoPlus);
	}
	if (Button_Spell3Plus)
	{
		Button_Spell3Plus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventThreePlus);
	}
	if (Button_Spell4Plus)
	{
		Button_Spell4Plus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventFourPlus);
	}
	if (Button_Spell5Plus)
	{
		Button_Spell5Plus->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventFivePlus);
	}
	if (LockOne)
	{
		LockOne->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventlockOne);
	}
	if (LockTwo)
	{
		LockTwo->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventlockTwo);
	}
	if (LockThree)
	{
		LockThree->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventlockThree);
	}
	else
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "could not find play button");
	}


	MagiBoltSpell = Cast<ASpell>(GetWorld()->SpawnActor(MagiBoltBP));
	WindSurgeSpell = Cast<ASpell>(GetWorld()->SpawnActor(WindSurgeBP));
	MageBlastSpell = Cast<ASpell>(GetWorld()->SpawnActor(MageBlastBP));
	BurningHandsSpell = Cast<ASpell>(GetWorld()->SpawnActor(BurningHandsBP));
	LightningStrikesSpell = Cast<ASpell>(GetWorld()->SpawnActor(LightningStrikesBP));


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

FString UUI_SpellMenu::APPowerOne()
{
	FString SpellPower = "/";
	if (MagiBoltSpell)
	{
		SpellPower = " " + FString::SanitizeFloat(MagiBoltSpell->APBonus);
	}
	return SpellPower;
}

FString UUI_SpellMenu::APPowerTwo()
{
	FString SpellPower = "/";
	if (WindSurgeSpell)
	{
		SpellPower = " " + FString::SanitizeFloat(WindSurgeSpell->APBonus);
	}
	return SpellPower;
}

FString UUI_SpellMenu::APPowerThree()
{
	FString SpellPower = "/";
	if (MageBlastSpell)
	{
		SpellPower = " " + FString::SanitizeFloat(MageBlastSpell->APBonus);
	}
	return SpellPower;
}

FString UUI_SpellMenu::APPowerFour()
{
	FString SpellPower = "/";
	if (BurningHandsSpell)
	{
		SpellPower = " " + FString::SanitizeFloat(BurningHandsSpell->APBonus);
	}
	return SpellPower;
}

FString UUI_SpellMenu::APPowerFive()
{
	FString SpellPower = "/";
	if (LightningStrikesSpell)
	{
		SpellPower = " " + FString::SanitizeFloat(LightningStrikesSpell->APBonus);
	}
	return SpellPower;
}

//Spell Control Buttons
void UUI_SpellMenu::OnClickEventOnePlus()
{
	SpellRank = 1;
	APAdditionCheck();

}

void UUI_SpellMenu::OnClickEventTwoPlus()
{
	SpellRank = 2;
	APAdditionCheck();
}

void UUI_SpellMenu::OnClickEventThreePlus()
{
	SpellRank = 3;
	APAdditionCheck();
}

void UUI_SpellMenu::OnClickEventFourPlus()
{
	SpellRank = 4;
	APAdditionCheck();
}


void UUI_SpellMenu::OnClickEventFivePlus()
{
	SpellRank = 5;
	APAdditionCheck();
}


void UUI_SpellMenu::OnClickEventlockOne()
{
	SpellRank = 6;
	APAdditionCheck();
}

void UUI_SpellMenu::OnClickEventlockTwo()
{
	SpellRank = 7;
	APAdditionCheck();
}

void UUI_SpellMenu::OnClickEventlockThree()
{
	SpellRank = 8;
	APAdditionCheck();
}

void UUI_SpellMenu::APAdditionCheck()
{
	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());
	if (MMC) {
		int CurAP = MMC->currentAP;
		if (CurAP >= 1)
		{
			MMC->SubtractAP();
			if (SpellRank == 1) { MagiBoltSpell->AddAPBonus(); }
			if (SpellRank == 2) { WindSurgeSpell->AddAPBonus(); }
			if (SpellRank == 3) { MageBlastSpell->AddAPBonus(); }
			if (SpellRank == 4) { BurningHandsSpell->AddAPBonus(); }
			if (SpellRank == 5) { LightningStrikesSpell->AddAPBonus(); }
			if (SpellRank == 6) { LockOne->SetVisibility(ESlateVisibility::Hidden); MageBlastSpell->UnlockSpell(); }
			if (SpellRank == 7) { LockTwo->SetVisibility(ESlateVisibility::Hidden); BurningHandsSpell->UnlockSpell(); }
			if (SpellRank == 8) { LockThree->SetVisibility(ESlateVisibility::Hidden); LightningStrikesSpell->UnlockSpell(); }
		}

	}
}

//Removal of APBonus from Spell
//void UUI_SpellMenu::APRemovalCheck()
//{
//
//	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());
//	if (MMC) {
//		int TotalAP = MMC->GetTotalAP();
//		int CurAP = MMC->currentAP;
//		int SpellAP = APPowerCount(); //something to add up all the AP spent on spells
//		int DiffAP = TotalAP - SpellAP;
//
//		if (CurAP < TotalAP && TotalAP == (CurAP + SpellAP))
//		{
//			MMC->AddAP();
//			if (SpellRank == 1) { MagiBoltSpell->SubtractAPBonus(); }
//			if (SpellRank == 2) { WindSurgeSpell->SubtractAPBonus(); }
//			if (SpellRank == 3) { MageBlastSpell->SubtractAPBonus(); }
//			if (SpellRank == 4) { BurningHandsSpell->SubtractAPBonus(); }
//			if (SpellRank == 5) { LightningStrikesSpell->SubtractAPBonus(); }
//		}
//
//	}
//
//}
//Adding APBonus to Spell


float UUI_SpellMenu::APPowerCount()
{
	SPower = MagiBoltSpell->APBonus + WindSurgeSpell->APBonus + MageBlastSpell->APBonus + BurningHandsSpell->APBonus + LightningStrikesSpell->APBonus;
	return SPower;
}

