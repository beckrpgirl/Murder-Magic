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
	//Gives the door a collision box in engine
	UPROPERTY(VisibleDefaultsOnly)
	UBoxComponent* CollisionBox;
	//Gives the door a mesh
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

	//Declares the function to begin overlap
	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);


	//declaration for the Open function to open the door
	void Open();
	//declaration for the transition function to give door the slide effect when it opens
	void Transition(float DeltaTime);
	//Declares float value for how far the door slides when opened
	UPROPERTY(EditAnywhere)
	float SlideDistance = 0.f;
	//Boolean for the transition
	bool isTransitioning = false;
    



};
