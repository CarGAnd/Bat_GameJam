// Fill out your copyright notice in the Description page of Project Settings.


#include "EchoLocation.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

// Sets default values for this component's properties
UEchoLocation::UEchoLocation()
{

}


void UEchoLocation::StartEchoLocation()
{
	if (!IsEchoLocationActive) {
		StartTime = UGameplayStatics::GetTimeSeconds(GetWorld());
	}
}

void UEchoLocation::StopEchoLocation()
{
	if (!IsEchoLocationActive) {
		float EndTime = UGameplayStatics::GetTimeSeconds(GetWorld());
		HeldDuration = EndTime - StartTime;

		StartTime = 0.0f;
		IsEchoLocationActive = true;

		OnStopEchoLocation(HeldDuration);
	}
}

