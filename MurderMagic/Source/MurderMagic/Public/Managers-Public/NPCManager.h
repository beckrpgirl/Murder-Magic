// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Templates.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "AITargetPoint.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPCManager.generated.h"

class ASpawner;
class ANPC;
UCLASS()
class MURDERMAGIC_API ANPCManager : public AActor
{
private:

	GENERATED_BODY()

	int currentLevel;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Sets default values for this actor's properties
	ANPCManager();

	UPROPERTY(EditAnywhere, Category = Reference, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<ANPC> GoblinRef;
	UPROPERTY(EditAnywhere, Category = Reference, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<ANPC> OgreRef;
	UPROPERTY(EditAnywhere, Category = Reference, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<ANPC> BossRef;

	ANPC* NPC;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetLevel(int level);
	int *GetLevel();


};
