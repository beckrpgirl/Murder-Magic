// Fill out your copyright notice in the Description page of Project Settings.


#include "LightningStrikes.h"

ALightningStrikes::ALightningStrikes(const FObjectInitializer& OI)
{
	spellCD = 3;
	range = 150;
	baseDMG = 15;
	SName = "LightingStrikes";
	PopulatePool(OI);
}

