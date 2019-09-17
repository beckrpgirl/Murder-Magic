// Fill out your copyright notice in the Description page of Project Settings.


#include "XPBar.h"
#include "MurderMagicCharacter.h"

float UXPBar::UpdateXPPercent() {

	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());

	return MMC->GetExperiencePercent();

}

