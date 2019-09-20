// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_LevelInfo.h"
#include "MurderMagicCharacter.h"

FString UUI_LevelInfo::CurrentLevel()
{
	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());
	if (MMC)
	{
		CLevel = "Level: " + FString::FromInt(MMC->CurrentPlayerLevel);

	}

	return CLevel;


}

FString UUI_LevelInfo::CurrentFloor()
{
	//ALoadLevel* LL = Cast<ALoadLevel>();
	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());
	if (MMC)
	{
		CFloor = "Floor: " + FString::FromInt(MMC->CurrentFloor);

	}

	return CFloor;


}
