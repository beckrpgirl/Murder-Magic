// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include <vector>
#include "Spell.generated.h"

class ANPC;
class AMurderMagicCharacter;

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API ASpell : public AActor
{
private:

	GENERATED_BODY()

public:

	float spellCD;
	float sinceCast;
	float range;
	float baseDMG;
	float APBonus;

	FTimerHandle Projectile_Handler;

	ASpell();
	ASpell *next;

	bool isUnlocked;
	void UnlockSpell();

	ANPC* Enemy;
	AMurderMagicCharacter* Character;

	FVector destination;

	UPROPERTY(VisibleDefaultsOnly)
	UTexture2D* SpellTexture;

	UPROPERTY(VisibleDefaultsOnly)
	USphereComponent* CollisionSphere;

	UPROPERTY(VisibleAnywhere, Category = "Spell Effect")
	class UParticleSystemComponent* PSC;

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ProjectileMovement();

	void CastSpell(FVector start, float angle);

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

	//virtual void CreateEffect() PURE_VIRTUAL(ASpell::CreateEffect);

	void AddAPBonus();
	void SubtractAPBonus();

};
