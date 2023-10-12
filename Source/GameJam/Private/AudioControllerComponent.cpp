// Fill out your copyright notice in the Description page of Project Settings.


#include "AudioControllerComponent.h"

void UAudioControllerComponent::PlayOneShotEvent3D(UFMODEvent* myEvent, const FTransform& Location)
{
	Instancewrapper = UFMODBlueprintStatics::PlayEventAtLocation(GetWorld(), myEvent, Location, true);
}
