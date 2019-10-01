// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHealthBar.h"

float UEnemyHealthBar::UpdateHealthPercent()
{
	return Character->GetHealthPercent();
}

void UEnemyHealthBar::SetCharacter(ANPC *npc)
{
	Character = npc;
}