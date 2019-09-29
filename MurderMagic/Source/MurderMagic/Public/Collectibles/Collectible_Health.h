// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectibleParent.h"
#include "Collectible_Health.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API ACollectible_Health : public ACollectibleParent
{
	GENERATED_BODY()

	ACollectible_Health(const FObjectInitializer& OI);

	UPROPERTY(EditDefaultsOnly, Category = Collectible)
	float HealthRecoveryAmount;

public:
	virtual bool OnInteract(AMurderMagicCharacter* pCharacter) override;
	
};
