// Fill out your copyright notice in the Description page of Project Settings.


#include "UI_TriggerCount.h"
#include "TriggerManager.h"
#include "Kismet/GameplayStatics.h"
#include "MurderMagicCharacter.h"

bool UUI_TriggerCount::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	//TM = Cast<ATriggerManager>(GetWorld()->SpawnActor(TMBP));

	return true;
}

FString UUI_TriggerCount::TriggerInfo()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATriggerManager::StaticClass(), TMArray);
	AMurderMagicCharacter* MMC = Cast<AMurderMagicCharacter>(GetOwningPlayerPawn());

	if (TMArray.Num() != 0) {

		TM = Cast<ATriggerManager>(TMArray[0]);

	}

	FString TrigMess = "Trigger x of x";
	if (TM)
	{
		TrigMess = "Triggers " + FString::FromInt(MMC->GetTriggersCollected()) + " of " + FString::FromInt(TM->TrigTotal);
	}
	return TrigMess;
}
