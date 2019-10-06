// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "SpellEffect.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MURDERMAGIC_API USpellEffect : public USceneComponent
{
private:

	GENERATED_BODY()



protected:

	// Called when the game starts
	virtual void BeginPlay() override;

	UParticleSystemComponent *PSC;

	UStaticMeshComponent *collisionShape;

public:	

	// Sets default values for this component's properties
	USpellEffect();

	UFUNCTION(BlueprintCallable)
	UParticleSystemComponent *GetPSC();

	UFUNCTION(BlueprintCallable)
	UStaticMeshComponent *GetCollisionShape();


	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
