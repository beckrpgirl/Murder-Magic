// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
//Includes for AI
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"

#include "NPCAIController.generated.h"

/**
 *
 */
UCLASS()
class MURDERMAGIC_API ANPCAIController : public AAIController
{
	GENERATED_BODY()


	ANPCAIController(const class FObjectInitializer& OI);

	//Called when the controller possesses a character Bot
	virtual void OnPossess(class APawn* InPawn) override;

	virtual void OnUnPossess() override;

	UBehaviorTreeComponent* BehaviorComp;
	UBlackboardComponent* BlackboardComp;


public:

	void SetTargetEnemy(APawn* NewTarget);

	FVector GetWaypointLocation();

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName TargetEnemyKeyName;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName CurrentWaypointKeyName;

};
