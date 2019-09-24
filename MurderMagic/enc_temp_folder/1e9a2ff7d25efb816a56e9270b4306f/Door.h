// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Door.generated.h"

UCLASS()
class MURDERMAGIC_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	UPROPERTY(VisibleDefaultsOnly)
	UBoxComponent* CollisionBox;

	UPROPERTY(VisibleDefaultsOnly)
	UStaticMeshComponent* Mesh;

	// Sets default values for this actor's properties
	ADoor();

protected:
	ADoor(const FObjectInitializer& OI);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

private:

	void Open();
	void Transition(float DeltaTime);

	UPROPERTY(EditAnywhere)
	float SlideDistance = 0.f;

	bool isTransitioning = false;
    



};
