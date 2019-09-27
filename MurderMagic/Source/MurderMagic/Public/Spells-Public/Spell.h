// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpellEffect.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
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

protected:

	std::vector <USpellEffect *> effects;

public:

	float spellCD;
	float sinceCast;
	float range;
	float baseDMG;

	ASpell();
	ASpell *next;

	ANPC* Enemy;
	AMurderMagicCharacter* Character;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* SpellTexture;

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* CollisionSphere;

	UPROPERTY(VisibleAnywhere, Category = "MovementComponent")
	UProjectileMovementComponent* ProjectileMovementComponent;

	UPROPERTY(VisibleAnywhere, Category = "Spell Effect")
	class UParticleSystemComponent* PSC;

	void CastSpell(FVector start, float angle);

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

	//virtual void CreateEffect() PURE_VIRTUAL(ASpell::CreateEffect);

};
