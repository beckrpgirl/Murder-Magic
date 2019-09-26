// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible_EXP.h"
#include "MurderMagicCharacter.h"

ACollectible_EXP::ACollectible_EXP(const FObjectInitializer& OI)
	: Super(OI)
{
}

bool ACollectible_EXP::OnInteract(AMurderMagicCharacter* pCharacter)
{

	if (pCharacter) {

		pCharacter->AddExperience(ExperienceGainAmount);

		Destroy();
		return true;

		if (GEngine) {

			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "Collected EXP collectible");

		}

	}

	return false;
}
