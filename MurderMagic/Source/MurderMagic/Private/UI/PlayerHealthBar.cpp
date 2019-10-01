// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHealthBar.h"
#include "MurderMagicCharacter.h"

float UPlayerHealthBar::UpdateHealthPercent()
{

	AMurderMagicCharacter *Character = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());

	return Character->GetHealthPercent();

}