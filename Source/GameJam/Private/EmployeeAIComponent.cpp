// Fill out your copyright notice in the Description page of Project Settings.

#include "Navigation/PathFollowingComponent.h"
#include "EmployeeAIComponent.h"

void UEmployeeAIComponent::UpdateCurrentTargetPosition(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	if (Result.IsFailure())
		return;

	if (currentTargetPositionIndex < patrolPositions.Num() - 1)
		currentTargetPositionIndex++;
	else
		currentTargetPositionIndex = 0;

	Patrol();
}

void UEmployeeAIComponent::SubscribeToRequestFinished()
{
	aiController->GetPathFollowingComponent()->OnRequestFinished.AddUObject(this, &UEmployeeAIComponent::UpdateCurrentTargetPosition);
}

void UEmployeeAIComponent::UnsubscribeToRequestFinished()
{
	aiController->GetPathFollowingComponent()->OnRequestFinished.RemoveAll(this);
}

// Sets default values for this component's properties
UEmployeeAIComponent::UEmployeeAIComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UEmployeeAIComponent::BeginPlay()
{
	Super::BeginPlay();

	APawn* Pawn = Cast<APawn>(GetOwner());

	if (IsValid(aiController))
		return;

	if (!IsValid(Pawn))
		return;

	aiController = Pawn->GetController<AAIController>();
	SubscribeToRequestFinished();
}


// Called every frame
void UEmployeeAIComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEmployeeAIComponent::Patrol()
{
	if (state != EmployeeAIState::Patrol)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not in Patrolling State."));
		return;
	}

	if (!IsValid(aiController))
	{
		UE_LOG(LogTemp, Warning, TEXT("No valid AI Controller."));
		return;
	}

	if (patrolPositions.Num() <= 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not enough patrol positions."));
		return;
	}

	aiController->MoveToActor(patrolPositions[currentTargetPositionIndex]);
}

