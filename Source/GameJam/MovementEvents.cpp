// Fill out your copyright notice in the Description page of Project Settings.

#include "EnhancedInputComponent.h"
#include "MovementEvents.h"
#include "GameJamCharacter.h"

// Sets default values for this component's properties
UMovementEvents::UMovementEvents()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UMovementEvents::SetupPlayerInputComponent(UEnhancedInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(MoveAction, ETriggerEvent::Started, this, &UMovementEvents::MoveStarted);
	PlayerInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &UMovementEvents::MoveStopped);
}


// Called when the game starts
void UMovementEvents::BeginPlay()
{
	Super::BeginPlay();
	AGameJamCharacter* jamCharacter = Cast<AGameJamCharacter>(GetOwner());
	if (IsValid(jamCharacter->enhancedInputComponent)) {
		SetupPlayerInputComponent(jamCharacter->enhancedInputComponent);
	}
	else {
		jamCharacter->OnPawnPossessed.AddDynamic(this, &UMovementEvents::SetupPlayerInputComponent);
	}	
}

void UMovementEvents::MoveStarted(const FInputActionValue& Value)
{
	OnPlayerStartedMoving.Broadcast();
}

void UMovementEvents::MoveStopped(const FInputActionValue& Value)
{
	OnPlayerStoppedMoving.Broadcast();
}


// Called every frame
void UMovementEvents::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

