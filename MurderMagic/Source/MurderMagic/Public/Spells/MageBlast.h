// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BeamSpell.h"
#include "CoreMinimal.h"
#include "Spell.h"
#include "MageBlast.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API AMageBlast : public ABeamSpell
{
private:

	GENERATED_BODY()

public:

	AMageBlast(const FObjectInitializer& ObjectInitializer);

	virtual void CastSpell(FTransform start) override;

};
