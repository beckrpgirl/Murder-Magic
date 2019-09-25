// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"

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
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPC::OnOverlapBegin);
	CollisionSphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
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

float ANPC::GetHealthPercent()
{
	return Health / MaxHealth;
}

bool ANPC::TakeDamage(int DamageAmount)
{
	Health -= DamageAmount;

	if (Health <= 0) {

		SpawnEXP(EXPWorth);
		Destroy();

	}

	return true;
}

void ANPC::SpawnEXP(int SpawnAmount)
{

	for (int i = 0; i <= SpawnAmount; i++) {

		GetWorld()->SpawnActor(ACollectible_EXP::StaticClass());

	}

}


void ANPC::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APawn* Pawn = Cast<APawn>(OtherActor);
	if (Pawn)
	{
		ANPCAIController* AIController = Cast<ANPCAIController>(GetController());
		if (AIController)
		{
			AIController->SetTargetEnemy(Pawn);
		}
	}
}