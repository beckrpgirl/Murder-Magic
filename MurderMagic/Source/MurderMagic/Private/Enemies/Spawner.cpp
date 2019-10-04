// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "MurderMagicCharacter.h"
#include "NPC.h"
#include "Engine/EngineTypes.h"
#include "NPCManager.h"
#include "UnrealMathUtility.h"

// Sets default values
ASpawner::ASpawner(const FObjectInitializer& OI)
	: Super(OI)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = OI.CreateDefaultSubobject<UBoxComponent>(this, TEXT("SphereComponent"));
	CollisionBox->GetCollisionResponseToChannel(ECC_WorldStatic);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ASpawner::OnOverlapBegin);
	SetRootComponent(CollisionBox);

}

void ASpawner::OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{	
	//Check to see if were colliding with MurderMagicCharacter
	AMurderMagicCharacter* PC = Cast<AMurderMagicCharacter>(OtherActor);
	if (PC)
	{
		//Spawn the waves
		SpawnWave();
		//remove the generate overlaps event.
		CollisionBox->SetGenerateOverlapEvents(false);
		//Remove the bind from memory(could also destroy objects)
		CollisionBox->OnComponentBeginOverlap.RemoveDynamic(this, &ASpawner::OnOverlapBegin);
	}
}

//Spawn wave, spawns the waves
void ASpawner::SpawnWave()
{
	if (SpawnZones.Num() == 0) {

		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "No Spawn points");
		}
		return;
	}
	if (UnitSpawnData.Num() == 0) {

		if (GEngine) {
			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "No enemies to spawn");
		}
		return;

	}


	FRotator Rotation = GetActorRotation();
	//Set spawn info
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.Owner = this;

	//Loop through the different SpawnData, Struct - Unit, Count.
	for (auto data : UnitSpawnData)
	{
		//Pick a random target point per wave
		FVector pos = SpawnZones[FMath::RandRange(0, SpawnZones.Num() - 1)]->GetActorLocation();

		//Pick a random number between the waves min and max counts.
		int count = FMath::RandRange(data.MinCount, data.MaxCount);
		//Loop through the random count spawning each unit x times.
		for (int i = 0; i < count; i++)
		{
			//pick a random location around the selected target point.
			pos.X = FMath::RandRange(pos.X - SpawnMaxDistance, pos.X + SpawnMaxDistance);
			pos.Y = FMath::RandRange(pos.Y - SpawnMaxDistance, pos.Y + SpawnMaxDistance);

			//Spawn unit.
			GetWorld()->SpawnActor<ANPC>(data.unit, pos, Rotation, SpawnInfo);
		}
	}
}

