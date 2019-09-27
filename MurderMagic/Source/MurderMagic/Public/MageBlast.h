// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Spell.h"
#include "CoreMinimal.h"
#include "Spell.h"
#include "MageBlast.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API AMageBlast : public ASpell
{
private:

	GENERATED_BODY()

public:

	AMageBlast();
	AMageBlast(ASpell* spell);
	ASpell* burningHandsRef;
	virtual void BeginPlay() override;

};
