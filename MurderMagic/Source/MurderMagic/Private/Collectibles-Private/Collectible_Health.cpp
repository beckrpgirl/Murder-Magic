// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible_Health.h"
#include "MurderMagicCharacter.h"

ACollectible_Health::ACollectible_Health(const FObjectInitializer& OI)
	: Super(OI)
{
}

bool ACollectible_Health::OnInteract(AMurderMagicCharacter* pCharacter)
{

	if (pCharacter) {

		pCharacter->AddHealth(HealthRecoveryAmount);

		Destroy();
		return true;

		if (GEngine) {

			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "Collected Health collectible");

		}

	}

	return false;
}
