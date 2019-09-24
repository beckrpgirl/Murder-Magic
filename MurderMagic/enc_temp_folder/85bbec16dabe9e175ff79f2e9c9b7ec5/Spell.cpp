// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"

ASpell::ASpell()
{
	spellCD = 0;
	sinceCast = 0;
	range = 0;
	baseDMG = 0;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionSphere->InitSphereRadius(40.0f);
	CollisionSphere->GetCollisionResponseToChannel(ECC_WorldStatic);
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionSphere->SetGenerateOverlapEvents(true);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ASpell::OnOverlapBegin);
	SetRootComponent(CollisionSphere);

	PSC = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComponent"));
	PSC->SetupAttachment(CollisionSphere);
	PSC->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void ASpell::Cast(FVector start, float angle)
{
	FVector destination;
	destination.X = start.X + (FMath::Cos(angle) * range);
	destination.Y = start.Y + (FMath::Sin(angle) * range);
	destination.Z = start.Z;

}

void ASpell::OnOverlapBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{



}
