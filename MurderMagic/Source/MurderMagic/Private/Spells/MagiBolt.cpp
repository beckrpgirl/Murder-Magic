// Fill out your copyright notice in the Description page of Project Settings.


#include "MagiBolt.h"
#include "Runtime/Engine/Classes/Engine/objectLibrary.h"
#include "ConstructorHelpers.h"

AMagiBolt::AMagiBolt(const FObjectInitializer& OI)
{
	spellCD = 3;
	range = 1500;
	baseDMG = 5;
	SName = "MagiBolt";
	UnlockSpell();
	maxPool = 5;
	lifeTime = 2.5;

	myRoot = OI.CreateDefaultSubobject<USphereComponent>(this, TEXT("myRoot"));
	RootComponent = myRoot;

	PopulatePool(OI);

	for (int i = 0; i < particlePool.Num(); ++i)
	{
		particlePool[i]->GetCollisionShape()->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
		particlePool[i]->AttachToComponent(myRoot, FAttachmentTransformRules::KeepWorldTransform);
	}
}

void AMagiBolt::CastSpell(FTransform start)
{
	SetActorTransform(start);
	FVector destination;
	destination.X = GetActorForwardVector().X * range;
	destination.Y = GetActorForwardVector().Y * range;
	destination += start.GetLocation();
	FTransform endTF = start;
	endTF.SetLocation(destination);
	USpellEffect *effect = GetInactiveEffect();
	if (effect != NULL)
	{
		effect->Init(start, endTF, lifeTime);
	}
}