// Fill out your copyright notice in the Description page of Project Settings.


#include "WindSurge.h"

AWindSurge::AWindSurge(const FObjectInitializer& OI)
{
	baseDMG = 5;
	lifeTime = 0.2;
	SetManaCost(20);
	range = 150;
	SName = "WindSurge";
	UnlockSpell();

	/*myRoot = OI.CreateDefaultSubobject<USphereComponent>(this, TEXT("myRoot"));
	RootComponent = myRoot;*/

	PopulatePool(OI);

	for (int i = 0; i < particlePool.Num(); ++i)
	{
		particlePool[i]->GetCollisionShape()->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
	}
}

float AWindSurge::CastSpell(FTransform start)
{
	SetActorTransform(start);
	FVector destination;
	destination.X = start.GetLocation().X + (GetActorForwardVector().X * range);
	destination.Y = start.GetLocation().Y + (GetActorForwardVector().Y * range);
	FVector startPoint = start.GetLocation();
	startPoint.X += GetActorForwardVector().X * 1;
	startPoint.Y += GetActorForwardVector().Y * 1;
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