// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Types.h"
#include "Spell.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API ASpell : public AActor
{
private:

	GENERATED_BODY()

protected:

	float spellCD;
	float sinceCast;
	float range;
	float baseDMG;

public:

	ASpell *next;

	ASpell();

	void Cast(FVector start, float angle);

	//virtual void CreateEffect() PURE_VIRTUAL(ASpell::CreateEffect);

};
