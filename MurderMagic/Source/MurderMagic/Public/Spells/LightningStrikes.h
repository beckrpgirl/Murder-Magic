// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BeamSpell.h"
#include "CoreMinimal.h"
#include "Spell.h"
#include "LightningStrikes.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API ALightningStrikes : public ABeamSpell
{
private:

	GENERATED_BODY()

public:

	ALightningStrikes(const FObjectInitializer& ObjectInitializer);

	virtual void CastSpell(FTransform start) override;

};
