// Fill out your copyright notice in the Description page of Project Settings.

#include "CustomPawnSensingComponent.h"

void UCustomPawnSensingComponent::SensePawn(APawn& Pawn)
{
	float distance = (Pawn.GetActorLocation() - GetOwner()->GetActorLocation()).Size();

	if (distance <= HearingThreshold) {
		BPEvent_OnPlayerWithinHearingRange.Broadcast(distance);
	}

	UPawnSensingComponent::SensePawn(Pawn);
}

float UCustomPawnSensingComponent::CalculatedVolume(float volume)
{
	return volume;
}
