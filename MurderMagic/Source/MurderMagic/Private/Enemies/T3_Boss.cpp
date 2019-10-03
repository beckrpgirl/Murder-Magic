// Fill out your copyright notice in the Description page of Project Settings.


#include "T3_Boss.h"
#include "BossDoor.h"



void AT3_Boss::ReduceHealth(int DamageAmount)
{
	Super::ReduceHealth(DamageAmount);

	if (GetHealthPercent() <= 0) 
	{

		SpawnEXP(GetXPValue());
		door->Open();
		Destroy();
		
	}
}