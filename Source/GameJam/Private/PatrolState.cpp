// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolState.h"
#include <Logging/StructuredLog.h>

PatrolState::PatrolState(UEmployeeAIComponent* owner_)
{
	owner = owner_;
}

void PatrolState::Enter()
{
	UE_LOGFMT(LogTemp, Log, "Entered state.");
}

void PatrolState::Execute()
{
	UE_LOGFMT(LogTemp, Log, "Ticked.");
}

void PatrolState::ExecuteFixed()
{
	UE_LOGFMT(LogTemp, Log, "Fixed Ticked.");
}

void PatrolState::Exit()
{
	UE_LOGFMT(LogTemp, Log, "Exited state.");
}
