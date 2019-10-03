// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "UObject/ConstructorHelpers.h"
#include "SpellSlots.h"
#include "Spell.h"
#include "MagiBolt.h"
#include "WindSurge.h"
#include "MageBlast.h"
#include "BurningHands.h"
#include "LightningStrikes.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpellManager.generated.h"

UCLASS()
class MURDERMAGIC_API ASpellManager : public AActor
{
private:

	GENERATED_BODY()

	ASpell* MagiBoltSpell;
	ASpell* WindSurgeSpell;
	ASpell* MageBlastSpell;
	ASpell* BurningHandsSpell;
	ASpell* LightningStrikesSpell;

	ASpell* equippedSpellL;
	ASpell* equippedSpellR;
	bool hasLeftUpdated;
	bool hasRightUpdated;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Sets default values for this actor's properties
	ASpellManager();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpell> MagiBoltBP;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpell> WindSurgeBP;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpell> MageBlastBP;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpell> BurningHandsBP;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpell> LightningStrikesBP;


	UPROPERTY() //The class (could also be done in a local function for a one-time go)
	TSubclassOf<UUserWidget> spellSlotRefClass;
	UPROPERTY() //The instance (your actual reference)
	USpellSlots* spellSlotRef;

	ASpell* GetLeftSpell();
	ASpell* GetRightSpell();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void NextSpellL();
	void NextSpellR();

	void CastSpellL(FVector start, FVector facingDirection, float angle);
	void CastSpellR(FVector start, FVector facingDirection, float angle);

	

};
