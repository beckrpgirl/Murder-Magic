// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectible_Mana.h"
#include "MurderMagicCharacter.h"

ACollectible_Mana::ACollectible_Mana(const FObjectInitializer& OI)
	: Super(OI)
{
}

bool ACollectible_Mana::OnInteract(AMurderMagicCharacter* pCharacter)
{

	if (pCharacter) {

		pCharacter->AddMana(ManaRecoveryAmount);

		Destroy();
		return true;

		if (GEngine) {

			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, "Collected Mana collectible");

		}

	}

	return false;
}
