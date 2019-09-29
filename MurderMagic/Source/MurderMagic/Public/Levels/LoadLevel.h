// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "LoadLevel.generated.h"

UCLASS()
class MURDERMAGIC_API ALoadLevel : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleDefaultsOnly)
		UBoxComponent* CollisionBox;

	UPROPERTY(VisibleDefaultsOnly)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = Level)
		FName NextFloorName;
	UPROPERTY(EditAnywhere, Category = Level)
		float CurrentFloorNum;


public:	
	// Sets default values for this actor's properties
	ALoadLevel(const FObjectInitializer& OI);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

	float XP;

};
