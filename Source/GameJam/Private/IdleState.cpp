// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleState.h"
#include <Logging/StructuredLog.h>
#include "EmployeeAIComponent.h"
#include <typeinfo>

UIdleState::UIdleState()
{
}

void UIdleState::Enter(UEmployeeAIComponent* owner_)
{
	owner = owner_;
	UE_LOGFMT(LogTemp, Log, "Entered idle state.");
}

void UIdleState::Execute()
{
	//UE_LOGFMT(LogTemp, Log, "Ticked.");
}

void UIdleState::ExecuteFixed()
{
	//UE_LOGFMT(LogTemp, Log, "Fixed Ticked.");
}

void UIdleState::Exit()
{
	UE_LOGFMT(LogTemp, Log, "Exited idle state.");
}

FString UIdleState::GetClassName()
{
	return "IdleState";
}
