// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SpellEffect.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "Components/SphereComponent.h"
#include <vector>
#include "Spell.generated.h"

class ANPC;
class AMurderMagicCharacter;

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API ASpell : public AActor
{
private:

	GENERATED_BODY()

protected:

	float spellCD;
	float sinceCast;
	float range;
	float baseDMG;
	float APBonus;

	int maxPool;

	TArray<USpellEffect *> particlePool;

public:

	FName SName;

	ASpell();
	ASpell *next;

	bool isUnlocked;
	void UnlockSpell();

	FVector destination;

	UPROPERTY(VisibleDefaultsOnly)
	UTexture2D* SpellTexture;

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void CastSpell(FTransform start) PURE_VIRTUAL(ASpell::CastSpell, );

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

	//virtual void CreateEffect() PURE_VIRTUAL(ASpell::CreateEffect);

	void PopulatePool(const FObjectInitializer& OI);
	UFUNCTION(BlueprintCallable)
	TArray<USpellEffect *> GetPool();

	void AddAPBonus();
	void SubtractAPBonus();
	float GetAPBonus();
	float SetAPBonus(float APPass);

};
