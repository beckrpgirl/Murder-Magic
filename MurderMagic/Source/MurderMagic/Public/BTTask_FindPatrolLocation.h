// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "NavigationSystem.h"
#include "NPCAIController.h"
#include "CoreMinimal.h"
//AI Module Includes
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Kismet/GameplayStatics.h"
#include "BTTask_FindPatrolLocation.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UBTTask_FindPatrolLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
		
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
