// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "MurderMagicCharacter.h"
#include "NPC.h"

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

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	Used = false;
	Location = GetActorLocation();
	Rotation = GetActorRotation();

}

// Called every frame
void ASpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawner::OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
	if (Used == false)
	{
		AMurderMagicCharacter* PC = Cast<AMurderMagicCharacter>(OtherActor);
		if (PC && ToSpawn)
		{
			if (GEngine)
				GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Orange, "PC and ToSpawn ok");

			SpawnNow = true;
			UWorld* world = GetWorld();
			if (world)
			{
				FActorSpawnParameters SpawnInfo;
				SpawnInfo.Owner = this;

				world->SpawnActor<ANPC>(ToSpawn,Location, Rotation, SpawnInfo);


				if (GEngine)
					GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Orange, "NPC Spawned");
			}

		}
	}


}

