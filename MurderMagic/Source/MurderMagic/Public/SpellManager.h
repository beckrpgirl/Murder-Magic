// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spell.h"
#include "SpellManager.generated.h"

UCLASS()
class MURDERMAGIC_API ASpellManager : public AActor
{
private:

	GENERATED_BODY()

	USpell *equippedSpellL;
	USpell *equippedSpellR;
	

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Sets default values for this actor's properties
	ASpellManager();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void NextSpellL();
	void NextSpellR();

	void CastSpellL();
	void CastSpellR();

};
