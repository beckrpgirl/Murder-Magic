// Fill out your copyright notice in the Description page of Project Settings.


#include "T3_Boss.h"
#include "BossDoor.h"



void AT3_Boss::TakeDamage(int DamageAmount)
{
	Super::TakeDamage(DamageAmount);

	if (GetHealthPercent() <= 0) 
	{

		SpawnEXP(GetXPValue());
		door->Open();
		Destroy();
		
	}
}