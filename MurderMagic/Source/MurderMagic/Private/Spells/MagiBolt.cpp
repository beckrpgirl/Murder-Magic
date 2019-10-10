// Fill out your copyright notice in the Description page of Project Settings.


#include "MagiBolt.h"
#include "Runtime/Engine/Classes/Engine/objectLibrary.h"
#include "ConstructorHelpers.h"

AMagiBolt::AMagiBolt(const FObjectInitializer& OI)
{
	spellCD = 3;
	range = 1000;
	baseDMG = 5;
	SName = "MagiBolt";
	UnlockSpell();
	maxPool = 5;
	lifeTime = 0.5;
	mCost = 20;

	myRoot = OI.CreateDefaultSubobject<USphereComponent>(this, TEXT("myRoot"));
	RootComponent = myRoot;

	PopulatePool(OI);

	for (int i = 0; i < particlePool.Num(); ++i)
	{
		particlePool[i]->GetCollisionShape()->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
	}
}

float AMagiBolt::CastSpell(FTransform start)
{
	SetActorTransform(start);
	FVector destination;
	destination.X = start.GetLocation().X + (GetActorForwardVector().X * range);
	destination.Y = start.GetLocation().Y + (GetActorForwardVector().Y * range);
	FVector startPoint = start.GetLocation();
	startPoint.X += GetActorForwardVector().X * 15;
	startPoint.Y += GetActorForwardVector().Y * 15;
	start.SetLocation(startPoint);
	USpellEffect *effect = GetInactiveEffect();
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