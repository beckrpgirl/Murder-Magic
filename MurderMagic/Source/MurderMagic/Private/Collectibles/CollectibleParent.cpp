// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectibleParent.h"
#include "MurderMagicCharacter.h"


ACollectibleParent::ACollectibleParent(const FObjectInitializer& OI)
	: Super(OI)
{

	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = OI.CreateDefaultSubobject<USphereComponent>(this, TEXT("SphereComponent"));
	CollisionSphere->InitSphereRadius(80.0f);
	CollisionSphere->GetCollisionResponseToChannel(ECC_WorldStatic);
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionSphere->SetGenerateOverlapEvents(true);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ACollectibleParent::OnOverlapBegin);
	SetRootComponent(CollisionSphere);

	Mesh = OI.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("MeshComponent"));
	Mesh->SetupAttachment(CollisionSphere);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Particle = OI.CreateDefaultSubobject<UParticleSystemComponent>(this, TEXT("ParticleComponent"));
	Particle->SetupAttachment(Mesh);
	Particle->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void ACollectibleParent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectibleParent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACollectibleParent::OnOverlapBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{

	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(OtherActor);

	if (MMC) {

		if (GEngine) {

			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "Collided with Collectible");

		}

	}

}

