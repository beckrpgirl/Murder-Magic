// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCAIController.h"
#include "NPC.h"


/* AI Specific includes */
#include "DetourCrowdAIController.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"


ANPCAIController::ANPCAIController(const class FObjectInitializer& OI)
{
	BehaviorComp = OI.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BlackboardComp = OI.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackboardComp"));

	TargetEnemyKeyName = "TargetEnemy";
	CurrentWaypointKeyName = "CurrentWaypoint";
}

void ANPCAIController::OnPossess(class APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ANPC* AIBot = Cast<ANPC>(InPawn);
	if (AIBot && AIBot->BehaviorTree)
	{
		if (AIBot->BehaviorTree->BlackboardAsset)
		{
			BlackboardComp->InitializeBlackboard(*AIBot->BehaviorTree->BlackboardAsset);
		}

		BehaviorComp->StartTree(*AIBot->BehaviorTree);
	}
}

void ANPCAIController::OnUnPossess()
{
	BehaviorComp->StopTree();
}

void ANPCAIController::SetTargetEnemy(APawn* NewTarget)
{
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsObject(TargetEnemyKeyName, NewTarget);
	}
}

FVector ANPCAIController::GetWaypointLocation()
{
	if (BlackboardComp)
		return Cast<AActor>(BlackboardComp->GetValueAsObject(CurrentWaypointKeyName))->GetActorLocation();


	return FVector::ZeroVector;
}