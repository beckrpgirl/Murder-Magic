// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ProjectileSpell.h"
#include "CoreMinimal.h"
#include "Spell.h"
#include "MagiBolt.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API AMagiBolt : public AProjectileSpell
{
private:

	GENERATED_BODY()

public:

	AMagiBolt(const FObjectInitializer& ObjectInitializer);

};
