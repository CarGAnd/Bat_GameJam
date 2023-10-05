// Fill out your copyright notice in the Description page of Project Settings.


#include "CanHideComponent.h"

// Sets default values for this component's properties
UCanHideComponent::UCanHideComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UCanHideComponent::SetIsHidden(bool _isHidden) {
	if (_isHidden && !isHidden) OnActorIsHiddenStarted.Broadcast();
	else if (!_isHidden && isHidden) OnActorIsHiddenStopped.Broadcast();
	isHidden = _isHidden;
}
bool UCanHideComponent::GetIsHidden() {
	return isHidden;
}

void UCanHideComponent::SetHiddenFactor(float _hiddenFactor)
{
	hiddenFactor = _hiddenFactor;
	OnActorIsHiddenAmount.Broadcast(hiddenFactor);
}

float UCanHideComponent::GetHiddenFactor()
{
	return hiddenFactor;
}


// Called when the game starts
void UCanHideComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCanHideComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

