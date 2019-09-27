// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectable_Death.h"
#include "MurderMagicCharacter.h"

ACollectable_Death::ACollectable_Death(const FObjectInitializer& OI)
	: Super(OI)
{
}

bool ACollectable_Death::OnInteract(AMurderMagicCharacter* pCharacter)
{

	return false;
}
