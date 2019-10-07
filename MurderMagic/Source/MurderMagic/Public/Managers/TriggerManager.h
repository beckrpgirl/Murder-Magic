// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Trigger.h"
#include "TriggerManager.generated.h"

class ADoor;

UCLASS()
class MURDERMAGIC_API ATriggerManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATriggerManager();
	//Added triggers in the engine via details tab
	UPROPERTY(EditAnywhere)
	TArray<ATrigger*> Triggers;


	//added doors to engine to be dragged in game
	UPROPERTY(EditAnywhere)
	ADoor* door;
	//Boolean to check if all triggers are active
	bool CheckIsActive();

	bool UpdateTrigsLeft();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//Not used-can be used for IsManagerActive
	bool IsActive;

	int TrigLeft;
	int TrigTotal;

};
