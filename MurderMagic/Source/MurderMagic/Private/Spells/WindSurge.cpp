// Fill out your copyright notice in the Description page of Project Settings.


#include "WindSurge.h"

AWindSurge::AWindSurge(const FObjectInitializer& OI)
{
	spellCD = 3;
	range = 150;
	baseDMG = 10;
	SName = "WindSurge";
	UnlockSpell();

	myRoot = OI.CreateDefaultSubobject<USphereComponent>(this, TEXT("myRoot"));
	RootComponent = myRoot;

	PopulatePool(OI);

	for (int i = 0; i < particlePool.Num(); ++i)
	{
		particlePool[i]->GetCollisionShape()->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
	}
}

float AWindSurge::CastSpell(FTransform start)
{
	return 0.0;
}