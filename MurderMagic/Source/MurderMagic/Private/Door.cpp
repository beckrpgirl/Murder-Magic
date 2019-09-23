// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"


// Sets default values
ADoor::ADoor(const FObjectInitializer& OI)
	: Super(OI)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = OI.CreateDefaultSubobject<UBoxComponent>(this, TEXT("SphereComponent"));
	CollisionBox->GetCollisionResponseToChannel(ECC_WorldStatic);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ADoor::OnOverlapBegin);
	SetRootComponent(CollisionBox);

	Mesh = OI.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("MeshComponent"));
	Mesh->SetupAttachment(CollisionBox);
	Mesh->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	
	Open();
	
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->Transition(DeltaTime);

}

void ADoor::OnOverlapBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
}

void ADoor::Open()
{
	this->isTransitioning = true;
}

void ADoor::Transition(float DeltaTime)
{
	if (this->isTransitioning)
	{
		float UpdatedYPosition = FMath::FInterpConstantTo(this->Mesh->RelativeLocation.Y, this->SlideDistance, DeltaTime, 100.f);
		this->Mesh->SetRelativeLocation(FVector{ 0.f,UpdatedYPosition, 0.f });
	}
	
}

