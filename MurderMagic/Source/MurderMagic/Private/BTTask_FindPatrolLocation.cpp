// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindPatrolLocation.h"


EBTNodeResult::Type UBTTask_FindPatrolLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ANPCAIController* AIC = Cast<ANPCAIController>(OwnerComp.GetAIOwner());
	if (!AIC)
		return EBTNodeResult::Failed;

	const float SearchRadius = 250.0f;
	const FVector SearchOrigin = AIC->GetWaypointLocation();

	FNavLocation ResultLocation;

	if (UNavigationSystemV1::K2_GetRandomReachablePointInRadius(AIC, SearchOrigin, ResultLocation.Location, SearchRadius))
	{
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(BlackboardKey.GetSelectedKeyID(), ResultLocation.Location);

		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
