// Fill out your copyright notice in the Description page of Project Settings.


#include "MageBlast.h"

AMageBlast::AMageBlast(const FObjectInitializer& OI)
{
	baseDMG = 10;
	lifeTime = 1;
	SetManaCost(40);
	range = 500;
	SName = "MageBlast";
	UnlockSpell();

	//myRoot = OI.CreateDefaultSubobject<USphereComponent>(this, TEXT("myRoot"));
	//RootComponent = myRoot;


	myRoot = OI.CreateDefaultSubobject<USphereComponent>(this, TEXT("myRoot"));
	RootComponent = myRoot;

	PopulatePool(OI);

	for (int i = 0; i < particlePool.Num(); ++i)
	{
		particlePool[i]->GetCollisionShape()->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
	}
	
}

float AMageBlast::CastSpell(FTransform start)
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