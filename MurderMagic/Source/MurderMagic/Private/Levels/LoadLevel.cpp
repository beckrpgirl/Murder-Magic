// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadLevel.h"
#include "MurderMagicCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MMGameInstance.h"


// Sets default values

ALoadLevel::ALoadLevel(const FObjectInitializer& OI)
	: Super(OI)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionBox = OI.CreateDefaultSubobject<UBoxComponent>(this, TEXT("SphereComponent"));
	CollisionBox->GetCollisionResponseToChannel(ECC_WorldStatic);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionBox->SetGenerateOverlapEvents(true);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ALoadLevel::OnOverlapBegin);
	SetRootComponent(CollisionBox);

	Mesh = OI.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("MeshComponent"));
	Mesh->SetupAttachment(CollisionBox);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);


}

// Called when the game starts or when spawned
void ALoadLevel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALoadLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALoadLevel::OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{

	AMurderMagicCharacter* PC = Cast<AMurderMagicCharacter>(OtherActor);
	UMMGameInstance* GI = Cast<UMMGameInstance>(GetGameInstance());
	if (GI && PC)
	{
		GI->PlayerXP = PC->GetExperience();
		GI->PlayerLvl = PC->CurrentPlayerLevel;
		GI->PlayerMaxXP = PC->GetMaxExperience();
		GI->PlayerAP = PC->currentAP;

		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Orange, "Current Level " + FString::FromInt(PC->GetMaxExperience()));

	UGameplayStatics::OpenLevel(this, NextFloorName, false);
	}
}

