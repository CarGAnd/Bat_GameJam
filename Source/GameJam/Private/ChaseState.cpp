// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseState.h"
#include <Logging/StructuredLog.h>
#include "EmployeeAIComponent.h"
#include <typeinfo>

UChaseState::UChaseState()
{
}

void UChaseState::SubscribeToRequestFinished()
{
	owner->aiController->GetPathFollowingComponent()->OnRequestFinished.AddUObject(this, &UChaseState::ChaseEnded);
}

void UChaseState::UnsubscribeToRequestFinished()
{
	//owner->aiController->GetPathFollowingComponent()->OnRequestFinished.RemoveAll(this);
	owner->aiController->GetPathFollowingComponent()->OnRequestFinished.Clear();
}

void UChaseState::Enter(UEmployeeAIComponent* owner_)
{
	UE_LOGFMT(LogTemp, Log, "Entered chase state.");
	owner = owner_;
	SubscribeToRequestFinished();
	UChaseState::ChaseTarget(owner->patrolWaitTime, owner->patrolAcceptanceRadius, owner->patrolStopOnOverlap, owner->patrolUsePathfinding, owner->patrolCanStrafe);
}

void UChaseState::Execute()
{
	//UE_LOGFMT(LogTemp, Log, "Ticked.");
}

void UChaseState::ExecuteFixed()
{
	//UE_LOGFMT(LogTemp, Log, "Fixed Ticked.");
}

void UChaseState::Exit()
{
	UE_LOGFMT(LogTemp, Log, "Exited chase state.");
	UnsubscribeToRequestFinished();
	owner->target = nullptr;
}

FString UChaseState::GetClassName()
{
	return "ChaseState";
}

// TODO: Consolidate with UPatrolState::Patrol in EmployeeAIComponent.
void UChaseState::ChaseTarget(float waitTime, float acceptanceRadius, bool stopOnOverlap, bool usePathfinding, bool canStrafe)
{
	if (!IsValid(owner->aiController))
	{
		UE_LOG(LogTemp, Warning, TEXT("No valid AI Controller."));
		return;
	}

	if (owner->target != nullptr)
	{
		owner->aiController->MoveToActor(
			owner->target,
			acceptanceRadius,
			stopOnOverlap,
			usePathfinding,
			canStrafe
		);

		return;
	}

	owner->aiController->MoveToLocation(
		owner->chaseLocation,
		acceptanceRadius,
		stopOnOverlap,
		usePathfinding,
		canStrafe
	);
}

void UChaseState::ChaseEnded(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	if (Result.IsSuccess()) {
		UE_LOGFMT(LogTemp, Log, "Player likely lost.");
	}

	if (Result.IsInterrupted()) {
		UE_LOGFMT(LogTemp, Log, "Chase was interrupted.");
		return;
	}

	if (Result.IsFailure()) {
		UE_LOGFMT(LogTemp, Log, "Chase ended in failure.");
	}

	owner->ChangeStateToPrevious();
}
