// Fill out your copyright notice in the Description page of Project Settings.


#include "XPBar.h"
#include "MurderMagicCharacter.h"

//binding for the exp progress bar
float UXPBar::UpdateXPPercent() {

	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());

	return MMC->GetExperiencePercent();

}

//Binding for the text on the exp bar
FString UXPBar::UpdateXP()
{
	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());
	if (MMC)
	{
		XProgress = FString::FromInt(MMC->GetExperience()) + " / " + FString::FromInt(MMC->GetMaxExperience());

	}
	else if (MMC->CurrentPlayerLevel == 10) {

		XProgress = "Max lvl reached";

	}

	return XProgress;

}

