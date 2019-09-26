// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CollectibleParent.h"
#include "Collectable_Death.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API ACollectable_Death : public ACollectibleParent
{
	GENERATED_BODY()

		ACollectable_Death(const FObjectInitializer& OI);

public:
	virtual bool OnInteract(AMurderMagicCharacter* pCharacter) override;

};
