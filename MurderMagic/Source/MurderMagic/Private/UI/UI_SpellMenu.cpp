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
#include "MMPlayerController.h"

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
		
		CheckVisability();

		//AMMPlayerController* PC = Cast<AMMPlayerController>(GetOwningPlayer());
		//if (PC && PC->GetSpellManager())
		//{
		//	ASpell* spell = PC->GetSpellManager()->GetMageBlast();
		//	if (spell && spell->isUnlocked == true)
		//	{
		//		LockOne->SetVisibility(ESlateVisibility::Hidden);
		//	}
		//}
	}
	if (LockTwo)
	{
		LockTwo->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventlockTwo);

		AMMPlayerController* PC = Cast<AMMPlayerController>(GetOwningPlayer());
		if (PC && PC->GetSpellManager())
		{
			ASpell* spell = PC->GetSpellManager()->GetLightningStrikes();
			if (spell && spell->isUnlocked == true)
			{
				LockTwo->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}
	if (LockThree)
	{
		LockThree->OnClicked.AddDynamic(this, &UUI_SpellMenu::OnClickEventlockThree);

		AMMPlayerController* PC = Cast<AMMPlayerController>(GetOwningPlayer());
		if (PC && PC->GetSpellManager())
		{
			ASpell* spell = PC->GetSpellManager()->GetBurningHands();
			if (spell && spell->isUnlocked == true)
			{
				LockThree->SetVisibility(ESlateVisibility::Hidden);
			}
		}
	}
	else
	{
		if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "could not find play button");
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
	FString SpellPower = " ";
	AMMPlayerController * PC = Cast<AMMPlayerController>(GetOwningPlayer());
	ASpell* spell = PC->GetSpellManager()->GetMagiBolt();
	if (spell)
	{
		SpellPower = " " + FString::FromInt(spell->GetAPBonus());
	}

	return SpellPower;
}

FString UUI_SpellMenu::APPowerTwo()
{
	FString SpellPower = " ";
	AMMPlayerController* PC = Cast<AMMPlayerController>(GetOwningPlayer());
	ASpell* spell = PC->GetSpellManager()->GetWindSurge();
	if (spell)
	{
		SpellPower = " " + FString::FromInt(spell->GetAPBonus());
	}

	return SpellPower;
}

FString UUI_SpellMenu::APPowerThree()
{
	FString SpellPower = " ";
	AMMPlayerController* PC = Cast<AMMPlayerController>(GetOwningPlayer());
	ASpell* spell = PC->GetSpellManager()->GetMageBlast();
	if (spell)
	{
		SpellPower = " " + FString::FromInt(spell->GetAPBonus());
	}

	return SpellPower;
}

FString UUI_SpellMenu::APPowerFour()
{
	FString SpellPower = " ";
	AMMPlayerController* PC = Cast<AMMPlayerController>(GetOwningPlayer());
	ASpell* spell = PC->GetSpellManager()->GetLightningStrikes();
	if (spell)
	{
		SpellPower = " " + FString::FromInt(spell->GetAPBonus());
	}

	return SpellPower;
}

FString UUI_SpellMenu::APPowerFive()
{
	FString SpellPower = " ";
	AMMPlayerController* PC = Cast<AMMPlayerController>(GetOwningPlayer());
	ASpell* spell = PC->GetSpellManager()->GetBurningHands();
	if (spell)
	{
		SpellPower = " " + FString::FromInt(spell->GetAPBonus());
	}

	return SpellPower;
}

//Spell Control Buttons
void UUI_SpellMenu::OnClickEventOnePlus()
{
	APAdditionCheck("MagiBolt");
}

void UUI_SpellMenu::OnClickEventTwoPlus()
{
	APAdditionCheck("WindSurge");
}

void UUI_SpellMenu::OnClickEventThreePlus()
{
	APAdditionCheck("MageBlast");
}

void UUI_SpellMenu::OnClickEventFourPlus()
{
	APAdditionCheck("LightingStrikes");
}


void UUI_SpellMenu::OnClickEventFivePlus()
{
	APAdditionCheck("BurningHands");
}


void UUI_SpellMenu::OnClickEventlockOne()
{
	APUnlock("MageBlast");
	if (Unlock == true)
	{
		LockOne->SetVisibility(ESlateVisibility::Hidden);
		Unlock = false;
	}
}

void UUI_SpellMenu::OnClickEventlockTwo()
{
	APUnlock("LightingStrikes");
	if (Unlock == true)
	{
		LockTwo->SetVisibility(ESlateVisibility::Hidden);
		Unlock = false;
	}
}

void UUI_SpellMenu::OnClickEventlockThree()
{
	APUnlock("BurningHands");
	if (Unlock == true)
	{
		LockThree->SetVisibility(ESlateVisibility::Hidden);
		Unlock = false;
	}
}

void UUI_SpellMenu::APAdditionCheck(FName BName)
{
	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());
	if (MMC) {
		int CurAP = MMC->currentAP;
		if (CurAP >= 1)
		{
			MMC->SubtractAP();
			if (GetOwningPlayer())
			{
				AMMPlayerController* PC = Cast<AMMPlayerController>(GetOwningPlayer());
				ASpell* spell = PC->GetSpellManager()->GetLeftSpell();

				int i = 0;
				while (spell && spell->SName != BName)
				{
					spell = spell->next;

					i++;
					if (i >= 10)
						spell = nullptr;
				}

				if (spell)
				{
					spell->AddAPBonus();
				}
				else
				{
					if (GEngine)
						GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "No Spell Found");
				}
			}
		}

	}
}

void UUI_SpellMenu::APUnlock(FName BName)
{
	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());
	if (MMC) {
		int CurAP = MMC->currentAP;
		if (CurAP >= 1)
		{
			MMC->SubtractAP();
			if (GetOwningPlayer())
			{
				AMMPlayerController* PC = Cast<AMMPlayerController>(GetOwningPlayer());
				ASpell* spell = PC->GetSpellManager()->GetLeftSpell();
				int i = 0;
				while (spell && spell->SName != BName)
				{
					spell = spell->next;

					i++;
					if (i >= 10)
						spell = nullptr;
				}

				if (spell) 
				{
					spell->UnlockSpell();
					Unlock = true;
				}
					
				else
				{
					if (GEngine)
						GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "No Spell Found");
				}
			}
		}

	}
}

void UUI_SpellMenu::CheckVisability()
{

	AMMPlayerController* PC = Cast<AMMPlayerController>(GetOwningPlayer());
	if (PC && PC->GetSpellManager())
	{
		ASpell* spell = PC->GetSpellManager()->GetMageBlast();
		if (spell && spell->isUnlocked == true)
		{
			LockOne->SetVisibility(ESlateVisibility::Hidden);
		}
	}





}

