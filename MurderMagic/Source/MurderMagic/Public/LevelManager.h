// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoadLevel.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "LevelManager.generated.h"



UCLASS()
class MURDERMAGIC_API ALevelManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelManager(const FObjectInitializer& OI);

	UPROPERTY(VisibleDefaultsOnly)
		UBoxComponent* CollisionBox;

	UPROPERTY(VisibleDefaultsOnly)
		UStaticMeshComponent* Mesh;


	UPROPERTY(EditAnywhere, Category = LevelContents)
		TArray<ALoadLevel*> LevelMapInformation;

	ALoadLevel* CurrentLvlMapInfo;

	void SetLevelManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void GetLevelInfo();


	//get level #
	//get enemy manager
	//reset needed counts


};
