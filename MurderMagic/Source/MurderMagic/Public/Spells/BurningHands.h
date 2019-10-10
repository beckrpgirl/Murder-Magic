// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ConeSpell.h"
#include "CoreMinimal.h"
#include "Spell.h"
#include "BurningHands.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API ABurningHands : public AConeSpell
{
private:

	GENERATED_BODY()

public:

	ABurningHands(const FObjectInitializer& ObjectInitializer);

	virtual float CastSpell(FTransform start) override;
};
