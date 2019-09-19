// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindBotWaypoint.h"

EBTNodeResult::Type UBTTask_FindBotWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ANPCAIController* AIC = Cast<ANPCAIController>(OwnerComp.GetAIOwner());
	if (!AIC)
		return EBTNodeResult::Failed;

	AActor* NewWaypoint;
	TArray<AActor*> AllWaypoint;

	UGameplayStatics::GetAllActorsOfClass(AIC, AAITargetPoint::StaticClass(), AllWaypoint);

	if (AllWaypoint.Num() == 0)
		return EBTNodeResult::Failed;

	//Find a new Waypoint randomly by index
	NewWaypoint = AllWaypoint[FMath::RandRange(0, AllWaypoint.Num() - 1)];

	if (NewWaypoint)
	{
		OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), NewWaypoint);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}
