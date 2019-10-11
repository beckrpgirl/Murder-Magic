// Fill out your copyright notice in the Description page of Project Settings.


#include "LightningStrikes.h"

ALightningStrikes::ALightningStrikes(const FObjectInitializer& OI)
{
	spellCD = 3;
	range = 600;
	baseDMG = 50;
	SName = "LightingStrikes";
	UnlockSpell();
	baseDMG = 10;
	lifeTime = 1;
	SetManaCost(50);

	//myRoot = OI.CreateDefaultSubobject<USphereComponent>(this, TEXT("myRoot"));
	//RootComponent = myRoot;

	PopulatePool(OI);

	for (int i = 0; i < particlePool.Num(); ++i)
	{
		particlePool[i]->GetCollisionShape()->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
	}
}

float ALightningStrikes::CastSpell(FTransform start)
{
	SetActorTransform(start);
	FVector destination;
	destination.X = start.GetLocation().X + (GetActorForwardVector().X * range);
	destination.Y = start.GetLocation().Y + (GetActorForwardVector().Y * range);
	FVector startPoint = start.GetLocation();
	startPoint.X += GetActorForwardVector().X * range;
	startPoint.Y += GetActorForwardVector().Y * range;
	start.SetLocation(startPoint);
	USpellEffect* effect = GetInactiveEffect();
	if (effect != NULL)
	{
		FTransform endTF = start;
		endTF.SetLocation(destination);
		effect->Init(start, endTF, lifeTime);

		return mCost;
	}
	else
	{
		return 0.0;
	}
}