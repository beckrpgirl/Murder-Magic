// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"
#include "NPC.h"
#include "MurderMagic.h"
#include "MurderMagicCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/Vector.h"
#include "Kismet/GameplayStatics.h"

ASpell::ASpell()
{

	PrimaryActorTick.bCanEverTick = true;

	isUnlocked = false;

}

void ASpell::UnlockSpell()
{
	isUnlocked = true;
}

void ASpell::BeginPlay()
{
	Super::BeginPlay();


}

void ASpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//function meant for later use when the enemies can take damage
void ASpell::OnOverlapBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{

	ANPC* Enemy = Cast<ANPC>(OtherActor);
	AMurderMagicCharacter* Character = Cast<AMurderMagicCharacter>(OtherActor);

	if (Enemy) {
		float DMG = baseDMG + APBonus;
		Enemy->ReduceHealth(DMG);

	}

	if (OtherActor != Character) {


	}

}

void ASpell::PopulatePool(const FObjectInitializer& OI)
{
	for (int i = 0; i < maxPool; i++)
	{
		particlePool.Add(OI.CreateDefaultSubobject<USpellEffect>(this, TEXT("PoolObject" + i)));
	}
}

TArray<USpellEffect *> ASpell::GetPool()
{
	return particlePool;
}

USpellEffect* ASpell::GetInactiveEffect()
{
	for (int i = 0; i < particlePool.Num(); ++i)
	{
		if (!particlePool[i]->Activated())
		{
			return particlePool[i];
		}
	}
	return NULL;
}

void ASpell::AddAPBonus()
{
	APBonus = APBonus + 1;
}

void ASpell::SubtractAPBonus()
{
	APBonus = APBonus - 1;
}

float ASpell::GetAPBonus()
{
	return APBonus;
}

float ASpell::SetAPBonus(float APPass)
{
	APBonus = APPass;
	return APBonus;
}
