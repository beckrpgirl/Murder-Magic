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
	//CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ASpawner::OnOverlapEnd);
	SetRootComponent(CollisionBox);

}

// Called when the game starts or when spawned
void ASpawner::BeginPlay()
{
	Super::BeginPlay();
	Used = false;
	SpawnNow = true;
	Location = GetActorLocation();
	Rotation = GetActorRotation();
	i = 1;
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
		if (PC && ToSpawn_1 && ToSpawn_2 && ToSpawn_3)
		{
			
			RandomNumber();
			XNPC = float(RNum);
			SpawnDelay();
		}
	}


}

void ASpawner::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
//Spawns random NPC with time delay
void ASpawner::SpawnDelay()
{	
	if (i <= XNPC)
	{
		RandomNPC();
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.Owner = this;
		float j = i * 10;
		FVector Location2 = FVector(i, j, 0.0f) + Location;
		if (K == 1){ GetWorld()->SpawnActor<ANPC>(ToSpawn_1, Location2, Rotation, SpawnInfo); }
		if (K == 2) { GetWorld()->SpawnActor<ANPC>(ToSpawn_2, Location2, Rotation, SpawnInfo); }
		if (K == 3) { GetWorld()->SpawnActor<ANPC>(ToSpawn_3, Location2, Rotation, SpawnInfo); }
		i++;
		GetWorld()->GetTimerManager().SetTimer(_TimerHandle, this, &ASpawner::SpawnDelay, TimeDelay, false);
	}
	else
	{
		SpawnNow = false;
		Used = true;
		i = 1;
	}
}

void ASpawner::RandomNPC()
{
	K = FMath::RandRange(1, 3);
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, "Timer");
}

int ASpawner::RandomNumber()
{
	RNum = FMath::RandRange(Min, Max);
	return RNum;
}

