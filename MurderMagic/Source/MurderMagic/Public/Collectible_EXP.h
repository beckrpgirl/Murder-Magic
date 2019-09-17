// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectibleParent.h"
#include "Collectible_EXP.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API ACollectible_EXP : public ACollectibleParent
{
	GENERATED_BODY()

	ACollectible_EXP(const FObjectInitializer& OI);

	UPROPERTY(EditDefaultsOnly, Category = "Experience")
	float ExperienceGainAmount;

public:
	virtual bool OnInteract(AMurderMagicCharacter* pCharacter) override;
	
};
