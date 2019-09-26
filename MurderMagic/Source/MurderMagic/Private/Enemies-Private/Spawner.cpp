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
			RandomNumber();
			XNPC = float(RNum);
			i = 1;
			SpawnDelay();
		}
	}


}

void ASpawner::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void ASpawner::SpawnDelay()
{
	if (GEngine)
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Orange, "NPC Spawned" + FString::FromInt(XNPC));
	
	if (i <= XNPC)
	{
		FActorSpawnParameters SpawnInfo;
		SpawnInfo.Owner = this;
		float j = i * 10;
		FVector Location2 = FVector(i, j, 0.0f) + Location;
		GetWorld()->SpawnActor<ANPC>(ToSpawn, Location2, Rotation, SpawnInfo);
		i++;
		GetWorld()->GetTimerManager().SetTimer(_TimerHandle, this, &ASpawner::SpawnDelay, 1.f, false);
	}
	else
	{
		SpawnNow = false;
		//Used = true;
	}
}

void ASpawner::EndTimer()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, "Timer");
}

int ASpawner::RandomNumber()
{
	RNum = FMath::RandRange(1, 5);
	return RNum;
}

