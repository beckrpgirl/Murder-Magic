// Fill out your copyright notice in the Description page of Project Settings.


#include "BurningHands.h"

ABurningHands::ABurningHands(const FObjectInitializer& OI)
{
	spellCD = 3;
	range = 0;
	baseDMG = 2;
	SName = "BurningHands";

	myRoot = OI.CreateDefaultSubobject<USphereComponent>(this, TEXT("myRoot"));
	RootComponent = myRoot;

	PopulatePool(OI);

	for (int i = 0; i < particlePool.Num(); ++i)
	{
		particlePool[i]->GetCollisionShape()->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
	}
	
}

void ABurningHands::CastSpell(FTransform start)
{

}