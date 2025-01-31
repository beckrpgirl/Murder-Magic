// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadLevel.h"
#include "MurderMagicCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "MMGameInstance.h"
#include "MMPlayerController.h"
#include "Spell.h"


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
	//AMMPlayerController* PC = Cast<AMMPlayerController>(GetOwningPlayer());
	//ASpell* spell = PC->GetSpellManager()->GetLeftSpell();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpellManager::StaticClass(), SMArray);
	if (SMArray.Num() != 0) {

		SM = Cast<ASpellManager>(SMArray[0]);

	}

	AMurderMagicCharacter* PCA = Cast<AMurderMagicCharacter>(OtherActor);
	UMMGameInstance* GI = Cast<UMMGameInstance>(GetGameInstance());
	if (GI && PCA)
	{
		//Player Info
		GI->PlayerXP = PCA->GetExperience();
		GI->PlayerLvl = PCA->CurrentPlayerLevel;
		GI->PlayerMaxXP = PCA->GetMaxExperience();
		GI->PlayerAP = PCA->currentAP;
		//Spell Info
		GI->MagiBoltUnlocked = SM->GetMagiBolt()->isUnlocked;
		GI->MagiBoltAP = SM->GetMagiBolt()->GetAPBonus();
		GI->WindSurgeUnlocked = SM->GetWindSurge()->isUnlocked;
		GI->WindSurgeAP = SM->GetWindSurge()->GetAPBonus();
		GI->MageBlastUnlocked = SM->GetMageBlast()->isUnlocked;
		GI->MageBlastAP = SM->GetMageBlast()->GetAPBonus();
		GI->BurningHandsUnlocked = SM->GetBurningHands()->isUnlocked;
		GI->BurningHandsAP = SM->GetBurningHands()->GetAPBonus();
		GI->LightingStrikesUnlocked = SM->GetLightningStrikes() ->isUnlocked;
		GI->LightingStrikesAP = SM->GetLightningStrikes()->GetAPBonus();


		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Orange, "Current Level " + FString::FromInt(PCA->GetMaxExperience()));

		UGameplayStatics::OpenLevel(this, NextFloorName, false);
	}
}

