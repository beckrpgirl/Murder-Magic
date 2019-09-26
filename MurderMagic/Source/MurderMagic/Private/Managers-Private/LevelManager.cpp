// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelManager.h"
#include "Templates.h"
#include "NPCManager.h"


// Sets default values
ALevelManager::ALevelManager(const FObjectInitializer& OI)
	: Super(OI)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ALevelManager::SetLevelManager()
{
	
}

// Called when the game starts or when spawned
void ALevelManager::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentLvlMapInfo = LevelMapInformation[0];

	SetLevelManager();

	firstTick = true;

}

// Called every frame
void ALevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (firstTick)
	{
		TArray<AMurderMagicCharacter*> player;
		FindAllActors(GetWorld(), player);
		player[0]->CurrentFloor = CurrentLvlMapInfo->CurrentFloorNum;
		this->player = player[0];
		TArray<ANPCManager *> npcManager;
		FindAllActors(GetWorld(), npcManager);
		npcManager[0]->SetLevel(CurrentLvlMapInfo->CurrentFloorNum);

		firstTick = false;
	}

	if (player->GetHealthPercent() <= 0)
	{
		
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetMapName()), false);
	}

}

void ALevelManager::GetLevelInfo()
{



}

