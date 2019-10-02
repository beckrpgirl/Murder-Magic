// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"
#include "NPC.h"
#include "MurderMagic.h"
#include "MurderMagicCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/Vector.h"
#include "Kismet/GameplayStatics.h"

ASpell::ASpell()
{

	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionSphere->InitSphereRadius(40.0f);
	CollisionSphere->GetCollisionResponseToChannel(ECC_WorldStatic);
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionSphere->SetCollisionObjectType(COLLISION_SPELLS);
	CollisionSphere->SetGenerateOverlapEvents(true);
	CollisionSphere->SetSimulatePhysics(false);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
	CollisionSphere->SetCollisionResponseToChannel(COLLISION_SPELLS, ECR_Ignore);
	SetRootComponent(CollisionSphere);


	PSC = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComponent"));
	PSC->SetupAttachment(CollisionSphere);
	PSC->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	isUnlocked = false;

}

void ASpell::UnlockSpell()
{
	isUnlocked = true;
}

void ASpell::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(Projectile_Handler, this, &ASpell::ProjectileMovement, 0.25, true);
	Projectile_Handler.Invalidate();

}

void ASpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpell::ProjectileMovement()
{

	FVector fDir = (GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorForwardVector()) * 50;
	FVector CurrentLocation = GetActorLocation();

	SetActorLocation(GetActorLocation() + fDir);

	if (destination != FVector::ZeroVector) {

		if ((destination -= CurrentLocation).Size() < 50.0f) {
			
			if (Projectile_Handler.IsValid()) {

				GetWorldTimerManager().ClearTimer(Projectile_Handler);

			}

		}

	}

	
}

void ASpell::CastSpell(FVector start, float angle)
{
	destination.X = start.X + (FMath::Cos(angle) * range);
	destination.Y = start.Y + (FMath::Sin(angle) * range);
	destination.Z = start.Z;
	SetActorLocation(start);
	GetWorld()->GetTimerManager().SetTimer(Projectile_Handler, this, &ASpell::ProjectileMovement, 0.25, true);

}

//function meant for later use when the enemies can take damage
void ASpell::OnOverlapBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{

	ANPC* Enemy = Cast<ANPC>(OtherActor);
	AMurderMagicCharacter* Character = Cast<AMurderMagicCharacter>(OtherActor);

	if (Enemy) {
		float DMG = baseDMG + APBonus;
		Enemy->TakeDamage(DMG);

	}

	if (OtherActor != Character) {

		GetWorld()->GetTimerManager().ClearAllTimersForObject(this);

	}

}

void ASpell::AddAPBonus()
{
	APBonus = APBonus + 1;
}

void ASpell::SubtractAPBonus()
{
	APBonus = APBonus - 1;
}
