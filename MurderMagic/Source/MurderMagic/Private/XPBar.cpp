// Fill out your copyright notice in the Description page of Project Settings.


#include "XPBar.h"
#include "MurderMagicCharacter.h"

float UXPBar::UpdateXPPercent() {

	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());

	return MMC->GetExperiencePercent();

}

FString UXPBar::UpdateXP()
{
	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());
	if (MMC)
	{
		XProgress = FString::FromInt(MMC->Experience) + " / " + FString::FromInt(MMC->ExperienceToNextLevel);

	}
	else if (MMC->CurrentPlayerLevel == 10) {

		XProgress = "Max lvl reached";

	}

	return XProgress;

}

