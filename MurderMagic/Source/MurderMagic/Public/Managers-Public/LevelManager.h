// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoadLevel.h"
#include "MurderMagicCharacter.h"
#include "LevelManager.generated.h"

class AMurderMagicCharacter;

UCLASS()
class MURDERMAGIC_API ALevelManager : public AActor
{
private:

	GENERATED_BODY()

	bool firstTick;

	AMurderMagicCharacter *player;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GetLevelInfo();
	
	// Sets default values for this actor's properties
	ALevelManager(const FObjectInitializer& OI);

	UPROPERTY(EditAnywhere, Category = LevelContents)
	TArray<ALoadLevel*> LevelMapInformation;

	UPROPERTY(EditAnywhere)
	FVector spawnPoint;

	ALoadLevel* CurrentLvlMapInfo;

	void SetLevelManager();



	//get level #
	//get enemy manager
	//reset needed counts


};
