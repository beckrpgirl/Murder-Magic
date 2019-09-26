// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Spell.h"
#include "CoreMinimal.h"
#include "Spell.h"
#include "WindSurge.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API AWindSurge : public ASpell
{
private:

	GENERATED_BODY()

public:

	AWindSurge();
	AWindSurge(ASpell* spell);
	ASpell* mageBlastRef;
	virtual void BeginPlay() override;
	
};
