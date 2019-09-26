// Fill out your copyright notice in the Description page of Project Settings.


#include "ManaBar.h"
#include "MurderMagicCharacter.h"

float UManaBar::UpdateManaPercent() {

	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());

	return MMC->GetManaPercent();

}