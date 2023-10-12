// Fill out your copyright notice in the Description page of Project Settings.

#include "EmployeeAIComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include <functional>
#include <typeinfo>

void UEmployeeAIComponent::InitializePatrolState(float waitTime, float acceptanceRadius, bool stopOnOverlap, bool usePathfinding, bool canStrafe)
{
	if (!patrolInitialized)
	{
		patrolWaitTime = waitTime;
		patrolAcceptanceRadius = acceptanceRadius;
		patrolStopOnOverlap = stopOnOverlap;
		patrolUsePathfinding = usePathfinding;
		patrolCanStrafe = canStrafe;
	}

	ChangeState(NewObject<UPatrolState>(this));
}

void UEmployeeAIComponent::InitializeChaseState(AActor* target_ = nullptr, FVector location = FVector(0,0,0))
{
	target = target_;
	chaseLocation = location;
	ChangeState(NewObject<UChaseState>(this));
}

void UEmployeeAIComponent::ChangeState(IState<UEmployeeAIComponent>* newState)
{
	if (!behaviourState.IsState(newState))
	{
		UE_LOGFMT(LogTemp, Log, "Change state was called.");
		behaviourState.ChangeState(newState, this);
	}
}

void UEmployeeAIComponent::ChangeStateToPrevious()
{
	behaviourState.ChangeStateToPrevious(this);
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
	ChangeState(NewObject<UIdleState>(this));
}


// Called every frame
void UEmployeeAIComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// behaviourState.Tick();
	// ...
}

