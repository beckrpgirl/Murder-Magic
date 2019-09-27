// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Spell.h"
#include "CoreMinimal.h"
#include "Spell.h"
#include "BurningHands.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API ABurningHands : public ASpell
{
private:

	GENERATED_BODY()

public:

	ABurningHands();
	ABurningHands(ASpell* spell);
	ASpell* lightningStrikesRef;
	virtual void BeginPlay() override;

};
