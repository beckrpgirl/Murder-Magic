// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MurderMagicCharacter.h"
#include "LevelManager.generated.h"

UCLASS()
class MURDERMAGIC_API ALevelManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	AMurderMagicCharacter* PC;

	void GetLevelInfo();

	//get level #
	//get enemy manager
	//reset needed counts


};
