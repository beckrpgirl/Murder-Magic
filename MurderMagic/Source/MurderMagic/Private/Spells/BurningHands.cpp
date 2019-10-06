// Fill out your copyright notice in the Description page of Project Settings.


#include "BurningHands.h"

ABurningHands::ABurningHands(const FObjectInitializer& OI)
{
	spellCD = 3;
	range = 0;
	baseDMG = 2;
	SName = "BurningHands";
	PopulatePool(OI);
	
}
