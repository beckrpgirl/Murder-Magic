// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Spell.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API USpell : public UObject
{
private:

	GENERATED_BODY()

	float spellCD;
	float sinceCast;
	float range;
	float baseDMG;

public:

	USpell *prev;
	USpell *next;

	USpell();

	void Cast();

};
