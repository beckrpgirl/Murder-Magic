// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectibleParent.h"
#include "Collectible_Mana.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API ACollectible_Mana : public ACollectibleParent
{
	GENERATED_BODY()

	ACollectible_Mana(const FObjectInitializer& OI);

	UPROPERTY(EditDefaultsOnly, Category = Collectible)
	float ManaRecoveryAmount;

public:
	virtual bool OnInteract(AMurderMagicCharacter* pCharacter) override;
	
};
