// Fill out your copyright notice in the Description page of Project Settings.


#include "LightningStrikes.h"

ALightningStrikes::ALightningStrikes(const FObjectInitializer& OI)
{
	spellCD = 3;
	range = 150;
	baseDMG = 15;
	SName = "LightingStrikes";
	PopulatePool(OI);

	for (int i = 0; i < particlePool.Num(); ++i)
	{
		particlePool[i]->GetCollisionShape()->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
	}
}

void ALightningStrikes::CastSpell(FTransform start)
{

}