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
	float lifeTime;
	float baseDMG;
	float APBonus;
	float mCost;

	int maxPool;

	UPROPERTY(VisibleAnywhere)
	TArray<USpellEffect *> particlePool;

	USphereComponent *myRoot;

public:

	FName SName;

	ASpell();
	ASpell *next;

	bool isUnlocked;
	void UnlockSpell();

	UPROPERTY(VisibleDefaultsOnly)
	UTexture2D* SpellTexture;

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual float CastSpell(FTransform start) PURE_VIRTUAL(ASpell::CastSpell, return 0.0;);

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

	void PopulatePool(const FObjectInitializer& OI);
	UFUNCTION(BlueprintCallable)
	TArray<USpellEffect *> GetPool();

	USpellEffect *GetInactiveEffect();

	void AddAPBonus();
	void SubtractAPBonus();
	float GetAPBonus();
	float SetAPBonus(float APPass);

	float GetManaCost();
	void SetManaCost(float cost);
};
