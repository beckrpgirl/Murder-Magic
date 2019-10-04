// Fill out your copyright notice in the Description page of Project Settings.


#include "MagiBolt.h"
#include "Runtime/Engine/Classes/Engine/objectLibrary.h"
#include "ConstructorHelpers.h"

AMagiBolt::AMagiBolt()
{
	spellCD = 3;
	range = 75;
	baseDMG = 5;
	//APBonus = 0;
	SName = "MagiBolt";
	UnlockSpell();
	maxPool = 5;
	for (int i = 0; i < maxPool; i++)
	{
		//particlePool.Add(*CreateDefaultSubobject<USpellEffect>(TEXT("PoolObject" + i)));
	}
}
