// Fill out your copyright notice in the Description page of Project Settings.


#include "MagiBolt.h"
#include "Runtime/Engine/Classes/Engine/objectLibrary.h"
#include "ConstructorHelpers.h"

AMagiBolt::AMagiBolt()
{
	spellCD = 3;
	range = 20;
	baseDMG = 10;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> PS(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Fire.P_Fire'"));

	PSC->SetTemplate(PS.Object);
}