// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "AITargetPoint.h"
#include "NPCAIController.h"
//AI Module Includes
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "Kismet/GameplayStatics.h"

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindBotWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UBTTask_FindBotWaypoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
		
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
