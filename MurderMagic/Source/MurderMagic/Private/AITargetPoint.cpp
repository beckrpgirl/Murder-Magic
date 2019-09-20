// Fill out your copyright notice in the Description page of Project Settings.


#include "AITargetPoint.h"

void AAITargetPoint::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Pawn = Cast<AMurderMagicCharacter>(OtherActor);
	if (Pawn)
	{
		if (OtherActor == Pawn) 
		{
			SpawnNow = true;
		}
	}
}

void AAITargetPoint::SpawnEnemies(int amount, int tier, TSubclassOf<ANPC> GoblinRef, TSubclassOf<ANPC> OgreRef, TSubclassOf<ANPC> BossRef)
{
	const FVector Location = this->GetActorLocation();
	const FRotator Rotation = this->GetActorRotation();
	const FActorSpawnParameters Params;
	UWorld* world = GetWorld();
	for (int i = 0; i < amount; i++)
	{
		ANPC* temp = world->SpawnActor<AT1_Goblin>(GoblinRef, Location, Rotation, Params);
	}
}