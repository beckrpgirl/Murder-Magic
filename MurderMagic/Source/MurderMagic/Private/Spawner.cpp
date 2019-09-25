// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "MurderMagicCharacter.h"
#include "NPC.h"
#include "Engine/EngineTypes.h"

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
	//CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ASpawner::OnOverlapEnd);
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
	AMurderMagicCharacter* PC = Cast<AMurderMagicCharacter>(OtherActor);
	if (Used == false && OtherActor == PC)
	{
		
		if (PC && ToSpawn)
		{
			//if (GEngine)
			//	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Orange, "PC and ToSpawn ok");

			SpawnNow = true;
			UWorld* world = GetWorld();
			if (world)
			{
				FActorSpawnParameters SpawnInfo;
				SpawnInfo.Owner = this;
				for (float i = 1; i < 5; i++)
				{
				
					FVector Location2 = FVector(0.0f, i, 0.0f) + Location;
					world->SpawnActor<ANPC>(ToSpawn, Location, Rotation, SpawnInfo);
					//SpawnDelay();

					//world->GetTimerManager().SetTimer(_TimerHandle, this, &ASpawner::EndTimer, 1.f, false);



					if (GEngine)
						GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Orange, "NPC Spawned" + FString::FromInt(i));
				}
			}

		}
	}


}

void ASpawner::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void ASpawner::SpawnDelay()
{
	GetWorld()->GetTimerManager().SetTimer(_TimerHandle, this, &ASpawner::EndTimer, 1.f, false);
}

void ASpawner::EndTimer()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, "Timer");
}

