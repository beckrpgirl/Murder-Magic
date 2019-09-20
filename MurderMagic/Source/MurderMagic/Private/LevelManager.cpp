// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "MurderMagicCharacter.h"


// Sets default values
ALevelManager::ALevelManager(const FObjectInitializer& OI)
	: Super(OI)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = OI.CreateDefaultSubobject<UBoxComponent>(this, TEXT("SphereComponent"));
	CollisionBox->GetCollisionResponseToChannel(ECC_WorldStatic);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ALevelManager::OnOverlapBegin);
	SetRootComponent(CollisionBox);

	Mesh = OI.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("MeshComponent"));
	Mesh->SetupAttachment(CollisionBox);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);



}

void ALevelManager::SetLevelManager()
{
	
}

// Called when the game starts or when spawned
void ALevelManager::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentLvlMapInfo = LevelMapInformation[0];

	SetLevelManager();

}

// Called every frame
void ALevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelManager::OnOverlapBegin(class UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMurderMagicCharacter* PC = Cast<AMurderMagicCharacter>(OtherActor);

	if (PC)
	{
		PC->CurrentLevelManager = this;
		PC->CurrentFloor = CurrentLvlMapInfo->CurrentFloorNum;

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "Current Level Manager level info Loaded");
	}
	else
	{
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "Fail to load Level Manager level info");
	}

}

void ALevelManager::GetLevelInfo()
{



}

