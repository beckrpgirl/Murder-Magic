// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Particles/ParticleSystemComponent.h"
#include "SpellEffect.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MURDERMAGIC_API USpellEffect : public UActorComponent
{
private:

	GENERATED_BODY()



protected:

	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Spell Effect")
	TAssetPtr<UParticleSystemComponent> PSC;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Particles", AssetRegistrySearchable, meta = (AssetBundles = "Particles"))
	TAssetPtr<UParticleSystem> ParticlePtr;

	// Sets default values for this component's properties
	USpellEffect();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
