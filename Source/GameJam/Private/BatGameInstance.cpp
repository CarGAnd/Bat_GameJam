// Fill out your copyright notice in the Description page of Project Settings.


#include "BatGameInstance.h"
#include "Engine/World.h"
#include "Misc/OutputDeviceRedirector.h"

DEFINE_LOG_CATEGORY_STATIC(GameStateLog, Log, All);
UBatGameInstance* UBatGameInstance::GetInstance(UObject* WorldContextObject)
{
    UWorld* World = WorldContextObject->GetWorld();
    if (World)
    {
        return Cast<UBatGameInstance>(World->GetGameInstance());
    }
    return nullptr;
}

void UBatGameInstance::ChangeGameState(EGameState NewState)
{
    UE_LOG(GameStateLog, Log, TEXT("Changing game state to: %s"), *UEnum::GetValueAsString<EGameState>(NewState));
    CurrentGameState = NewState;

    switch (NewState)
    {
    case EGameState::PauseGameState:
        OnGamePausedEvent.Broadcast();
        break;
    case EGameState::IntroSceneState:
        OnGameStartedEvent.Broadcast();
        break;
    case EGameState::GameOverState:
        OnGameOverEvent.Broadcast();
        break;
    case EGameState::WonGameState:
        OnGameWonEvent.Broadcast();
        break;
    case EGameState::PlayingGameState:
        OnGamePlayingEvent.Broadcast();
        break;
    }
}


EGameState UBatGameInstance::GetCurrentGameState() const
{
    return CurrentGameState;
}