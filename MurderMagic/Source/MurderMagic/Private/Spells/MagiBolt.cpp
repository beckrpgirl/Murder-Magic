// Fill out your copyright notice in the Description page of Project Settings.


#include "MagiBolt.h"
#include "Runtime/Engine/Classes/Engine/objectLibrary.h"
#include "ConstructorHelpers.h"

AMagiBolt::AMagiBolt(const FObjectInitializer& OI)
{
	spellCD = 3;
	range = 75;
	baseDMG = 5;
	SName = "MagiBolt";
	UnlockSpell();
	maxPool = 5;
	PopulatePool(OI);
}
