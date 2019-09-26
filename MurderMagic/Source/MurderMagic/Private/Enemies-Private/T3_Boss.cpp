// Fill out your copyright notice in the Description page of Project Settings.


#include "T3_Boss.h"
#include "BossDoor.h"



bool AT3_Boss::TakeDamage(int DamageAmount)
{
	Health -= DamageAmount;

	if (Health <= 0) {

		SpawnEXP(EXPWorth);
		Destroy();
		door->Open();
		

	}

	return true;
}