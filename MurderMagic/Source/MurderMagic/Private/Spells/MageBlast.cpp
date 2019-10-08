// Fill out your copyright notice in the Description page of Project Settings.


#include "MageBlast.h"

AMageBlast::AMageBlast(const FObjectInitializer& OI)
{
	spellCD = 3;
	range = 60;
	baseDMG = 10;
	SName = "MageBlast";

	myRoot = OI.CreateDefaultSubobject<USphereComponent>(this, TEXT("myRoot"));
	RootComponent = myRoot;

	PopulatePool(OI);

	for (int i = 0; i < particlePool.Num(); ++i)
	{
		particlePool[i]->GetCollisionShape()->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
	}
	
}

void AMageBlast::CastSpell(FTransform start)
{

}