// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SpellSlots.h"
#include "MagiBolt.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spell.h"
#include "SpellManager.generated.h"

UCLASS()
class MURDERMAGIC_API ASpellManager : public AActor
{
private:

	GENERATED_BODY()

	ASpell *equippedSpellL;
	ASpell *equippedSpellR;
	

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Sets default values for this actor's properties
	ASpellManager();

	ASpell* GetLeftSpell();
	ASpell* GetRightSpell();

	ASpell* equippedSpellL;
	ASpell* equippedSpellR;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void NextSpellL();
	void NextSpellR();

	void CastSpellL(FVector start, float angle);
	void CastSpellR(FVector start, float angle);

};
