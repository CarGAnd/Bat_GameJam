// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolState.h"
#include <Logging/StructuredLog.h>
#include "EmployeeAIComponent.h"
#include <typeinfo>

void UPatrolState::SubscribeToRequestFinished()
{
	owner->aiController->GetPathFollowingComponent()->OnRequestFinished.AddUObject(this, &UPatrolState::UpdateCurrentTargetPosition);
}

void UPatrolState::UnsubscribeToRequestFinished()
{
	owner->aiController->GetPathFollowingComponent()->OnRequestFinished.Clear();
}

void UPatrolState::UpdateCurrentTargetPosition(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	if (Result.IsFailure())
		return;

	if (owner->currentTargetPositionIndex < owner->patrolPositions.Num() - 1)
		owner->currentTargetPositionIndex++;
	else
		owner->currentTargetPositionIndex = 0;

	Patrol(owner->patrolWaitTime, owner->patrolAcceptanceRadius, owner->patrolStopOnOverlap, owner->patrolUsePathfinding, owner->patrolCanStrafe);
}

void UPatrolState::Patrol(float waitTime, float acceptanceRadius, bool stopOnOverlap, bool usePathfinding, bool canStrafe)
{
	if (!IsValid(owner->aiController))
	{
		UE_LOG(LogTemp, Warning, TEXT("No valid AI Controller."));
		return;
	}

	if (owner->patrolPositions.Num() <= 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not enough patrol positions."));
		return;
	}

	owner->aiController->MoveToActor(
		owner->patrolPositions[owner->currentTargetPositionIndex],
		acceptanceRadius,
		stopOnOverlap,
		usePathfinding,
		canStrafe
	);
}

UPatrolState::UPatrolState()
{
}

void UPatrolState::Enter(UEmployeeAIComponent* owner_)
{
	UE_LOGFMT(LogTemp, Log, "Entered patrol state.");
	owner = owner_;
	SubscribeToRequestFinished();
	UPatrolState::Patrol(owner->patrolWaitTime, owner->patrolAcceptanceRadius, owner->patrolStopOnOverlap, owner->patrolUsePathfinding, owner->patrolCanStrafe);
}

void UPatrolState::Execute()
{
	//UE_LOGFMT(LogTemp, Log, "Ticked.");
}

void UPatrolState::ExecuteFixed()
{
	//UE_LOGFMT(LogTemp, Log, "Fixed Ticked.");
}

void UPatrolState::Exit()
{
	UE_LOGFMT(LogTemp, Log, "Exited patrol state.");
	UnsubscribeToRequestFinished();
}

FString UPatrolState::GetClassName()
{
	return "PatrolState";
}