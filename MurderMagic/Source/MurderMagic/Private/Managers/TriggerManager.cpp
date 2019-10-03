// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerManager.h"
#include "Trigger.h"
#include "Templates.h"
#include "Door.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATriggerManager::ATriggerManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
//Boolean checking if there are no active triggers then returns true
bool ATriggerManager::CheckIsActive()
{//Looping through triggers
	int i;
	for (i = 0; i < Triggers.Num(); i++)
	{
		//returns false if any trigger is not active
		if (!Triggers[i]->DidActivate)
			return false;

		TrigLeft = i;
	}
	return true;
}


// Called when the game starts or when spawned
void ATriggerManager::BeginPlay()
{
	Super::BeginPlay();

	TrigTotal = Triggers.Num();
	
}

// Called every frame
void ATriggerManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Opens door  if all the triggers are active
	if (CheckIsActive())
	{
		//calls function opens door 
		door->Open();
	}


}



