// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameJamGameMode.h"
#include "GameJamCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGameJamGameMode::AGameJamGameMode()
{
	// set default pawn class to our Blueprinted character

    DefaultPawnClass = nullptr;

}

APawn* AGameJamGameMode::SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot)
{
    // Intentionally left empty to prevent spawning.
    return nullptr;
}

