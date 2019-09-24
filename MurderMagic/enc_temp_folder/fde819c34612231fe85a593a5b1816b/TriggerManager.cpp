// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerManager.h"
#include "Trigger.h"
#include "Templates.h"
#include "TriggerDoor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATriggerManager::ATriggerManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATriggerManager::GetAllTriggers()
{

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATrigger::StaticClass(), HasNotInteracted);

	for (int i = 0; i < HasNotInteracted.Num(); i++) {

		TotalUnusedTriggers = i;


	}

}

void ATriggerManager::GetTriggerDoors()
{
	TArray<ATriggerDoor*> door;
	FindAllActors(GetWorld(), door);

}

// Called when the game starts or when spawned
void ATriggerManager::BeginPlay()
{
	Super::BeginPlay();
	GetAllTriggers();
	
}

// Called every frame
void ATriggerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Trigger && (HasNotInteracted.Num() != 0)) {

		if ((Trigger->DidActivate) == true) {

			HasNotInteracted.Remove(Trigger);
			HasInteracted.Add(Trigger);

		}
		else if ((Trigger->DidActivate) == false) {

			HasInteracted.Remove(Trigger);
			HasNotInteracted.Add(Trigger);

		}

	}

}

