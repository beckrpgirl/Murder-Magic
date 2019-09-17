// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ParticleHelper.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "CollectibleParent.generated.h"


class AMurderMagicCharacter;

UCLASS()
class MURDERMAGIC_API ACollectibleParent : public AActor
{
	GENERATED_BODY()
	
public:

	USphereComponent* CollisionSphere;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleDefaultsOnly)
	UParticleSystemComponent* Particle;

	// Sets default values for this actor's properties
	ACollectibleParent(const FObjectInitializer& OI);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

	UFUNCTION()
	virtual bool OnInteract(AMurderMagicCharacter* pCharacter) PURE_VIRTUAL(ACollectible::OnInteract, return false;);

};
