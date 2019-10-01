// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"
#include "NPC.h"
#include "MurderMagic.h"
#include "Kismet/KismetMathLibrary.h"

ASpell::ASpell()
{

	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionSphere->InitSphereRadius(40.0f);
	CollisionSphere->GetCollisionResponseToChannel(ECC_WorldStatic);
	CollisionSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionSphere->SetCollisionObjectType(COLLISION_SPELLS);
	CollisionSphere->SetGenerateOverlapEvents(true);
	//CollisionSphere->SetSimulatePhysics(true);
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

	GetWorld()->GetTimerManager().SetTimer(Projectile_Handler, this, &ASpell::ProjectileMovement, 1, true);
	Projectile_Handler.Invalidate();

}

void ASpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void ASpell::ProjectileMovement()
{

	//CollisionSphere->SetPhysicsLinearVelocity(FVector(), true, NAME_None);

	FVector fDir = GetActorForwardVector() * 100;

	SetActorLocation(GetActorLocation() + fDir);
	
}

void ASpell::CastSpell(FVector start, float angle)
{
	FVector destination;
	destination.X = start.X + (FMath::Cos(angle) * range);
	destination.Y = start.Y + (FMath::Sin(angle) * range);
	destination.Z = start.Z;
	SetActorLocation(start);
	Projectile_Handler.IsValid();

}

//function meant for later use when the enemies can take damage
void ASpell::OnOverlapBegin(UPrimitiveComponent* OverlapComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit)
{

	Enemy = Cast<ANPC>(OtherActor);

	if (Enemy) {

		Enemy->TakeDamage(baseDMG);

	}


}
