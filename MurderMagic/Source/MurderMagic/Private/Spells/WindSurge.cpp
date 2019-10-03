// Fill out your copyright notice in the Description page of Project Settings.


#include "WindSurge.h"

AWindSurge::AWindSurge()
	: Super()
{
	spellCD = 3;
	range = 150;
	baseDMG = 10;
	APBonus = 0;

	SName = "WindSurge";
	UnlockSpell();
}
