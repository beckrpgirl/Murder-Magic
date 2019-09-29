// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"


// Sets default values
ADoor::ADoor(const FObjectInitializer& OI)
	: Super(OI)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Parameters for the collision box
	CollisionBox = OI.CreateDefaultSubobject<UBoxComponent>(this, TEXT("SphereComponent"));
	CollisionBox->GetCollisionResponseToChannel(ECC_WorldStatic);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ADoor::OnOverlapBegin);
	SetRootComponent(CollisionBox);
	//Parameters for the static mesh
	Mesh = OI.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("MeshComponent"));
	Mesh->SetupAttachment(CollisionBox);
	Mesh->AttachToComponent(this->RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->Transition(DeltaTime);

}

//Begin overlap function for door
void ADoor::OnOverlapBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{
}

//Function Definition of Open
void ADoor::Open()
{
	//Calls Transition function if the prequisites are completed and is returned true
	this->isTransitioning = true;
}

//Function Definition of Transition
void ADoor::Transition(float DeltaTime)
{
	//calls If statement
	if (this->isTransitioning)
	{
		//Updates position via float value and slides door along Y axis thus moving the door and opening it
		float UpdatedYPosition = FMath::FInterpConstantTo(this->Mesh->RelativeLocation.Y, this->SlideDistance, DeltaTime, 100.f);
		this->Mesh->SetRelativeLocation(FVector{ 0.f,UpdatedYPosition, 0.f });
	}
	
}

