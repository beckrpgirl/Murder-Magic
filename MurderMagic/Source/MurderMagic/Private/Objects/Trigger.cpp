// Fill out your copyright notice in the Description page of Project Settings.


#include "Trigger.h"
#include "MurderMagicCharacter.h"



// Sets default values
ATrigger::ATrigger(const FObjectInitializer& OI)
	: Super(OI)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = OI.CreateDefaultSubobject<UBoxComponent>(this, TEXT("BoxComponent"));
	CollisionBox->InitBoxExtent(FVector(60, 40, 40));
	CollisionBox->GetCollisionResponseToChannel(ECC_WorldStatic);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBox->SetGenerateOverlapEvents(true);
	SetRootComponent(CollisionBox);

	Mesh = OI.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("MeshComponent"));
	Mesh->SetupAttachment(CollisionBox);
	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	Particle = OI.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("ParticleComponent"));
	Particle->SetupAttachment(Mesh);
	Particle->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	DidActivate = false;
	CanActivate = true;

}

bool ATrigger::ToggleInteracted()
{

	if (DidActivate == false) {

		DidActivate = true;

	}
	else {

		DidActivate = false;

	}


	return DidActivate;
}

// Called when the game starts or when spawned
void ATrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATrigger::OnInteract()
{
	if (CanActivate == true)
	{
		ToggleInteracted();
		CanActivate = false;
	}
	return false;
}

