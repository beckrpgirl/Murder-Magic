// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ParticleHelper.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"


#include "Trigger.generated.h"

class AMurderMagicCharacter;

UCLASS()
class MURDERMAGIC_API ATrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrigger(const FObjectInitializer& OI);

	UBoxComponent* CollisionBox;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleDefaultsOnly)
	UParticleSystemComponent* Particle;

	bool DidActivate;
	bool CanActivate;

	bool ToggleInteracted();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool OnInteract();

};
