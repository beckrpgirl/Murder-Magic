// Fill out your copyright notice in the Description page of Project Settings.


#include "MageBlast.h"

AMageBlast::AMageBlast(const FObjectInitializer& OI)
{
	spellCD = 3;
	range = 60;
	baseDMG = 10;
	SName = "MageBlast";
	PopulatePool(OI);
	
}