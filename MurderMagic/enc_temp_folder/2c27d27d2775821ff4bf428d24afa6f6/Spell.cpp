// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"
#include "NPC.h"
#include "MurderMagic.h"

ASpell::ASpell()
{

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionSphere->InitSphereRadius(40.0f);
	CollisionSphere->GetCollisionResponseToChannel(ECC_WorldStatic);
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionSphere->SetCollisionObjectType(COLLISION_SPELLS);
	CollisionSphere->SetGenerateOverlapEvents(true);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
	CollisionSphere->SetCollisionResponseToChannel(COLLISION_SPELLS, ECR_Ignore);
	SetRootComponent(CollisionSphere);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionSphere);
	ProjectileMovementComponent->InitialSpeed = 3000.0f;
	ProjectileMovementComponent->MaxSpeed = 3000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = false;


	PSC = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComponent"));
	PSC->SetupAttachment(CollisionSphere);
	PSC->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ASpell::CastSpell(FVector start, float angle)
{
	FVector destination;
	destination.X = start.X + (FMath::Cos(angle) * range);
	destination.Y = start.Y + (FMath::Sin(angle) * range);
	destination.Z = start.Z;

}

//function meant for later use when the enemies can take damage
void ASpell::OnOverlapBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{

	Enemy = Cast<ANPC>(OtherActor);

	if (Enemy) {

		Enemy->TakeDamage(baseDMG);

	}


}
