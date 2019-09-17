// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBar.h"
#include "MurderMagicCharacter.h"


float UHealthBar::UpdateHealthPercent() {

	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());

	return MMC->GetHealthPercent();

}