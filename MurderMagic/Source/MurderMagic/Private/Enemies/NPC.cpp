// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"
#include "Collectible_EXP.h"
#include "Math/Vector.h"
#include "Components/PrimitiveComponent.h"

// Sets default values
ANPC::ANPC(const FObjectInitializer& OI)
{
	AIControllerClass = ANPCAIController::StaticClass();
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = OI.CreateDefaultSubobject<USphereComponent>(this, TEXT("SphereComponent"));
	CollisionSphere->InitSphereRadius(500.0f);
	CollisionSphere->SetCollisionResponseToAllChannels(ECR_Overlap);
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionSphere->SetGenerateOverlapEvents(true);
	CollisionSphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	hpBar = OI.CreateDefaultSubobject<UWidgetComponent>(this, TEXT("HP Bar"));
}

// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	ANPCAIController* AIController = Cast<ANPCAIController>(GetController());
	if (AIController)
	{
		AIController->SetTargetEnemy(GetWorld()->GetFirstPlayerController()->GetPawn());
	}
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANPC::SetHealth(float hp)
{
	Health = hp;
}

float ANPC::GetHealthPercent()
{
	return Health / MaxHealth;
}

void ANPC::TakeDamage(int DamageAmount)
{
	Health -= DamageAmount;

	if (Health <= 0) {

		SpawnEXP(EXPWorth);
		Destroy();

	}
}

void ANPC::SpawnEXP(int SpawnAmount)
{
	FVector Location;
	Location = GetActorLocation();

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (EXPPickup) {

		for (int i = 0; i <= SpawnAmount; i++) {

			Location.X += (FMath::RandRange(0, 75));
			Location.Y += (FMath::RandRange(0, 75));


			ACollectible_EXP* XPCollectible = GetWorld()->SpawnActor<ACollectible_EXP>(EXPPickup, SpawnInfo);
			XPCollectible->SetActorLocation(Location);

		}

	}

}

float ANPC::GetDamage()
{
	return Damage;
}

int ANPC::GetXPValue()
{
	return EXPWorth;
}