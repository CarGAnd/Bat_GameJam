// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomEmployeeAIComponent.h"

UCustomEmployeeAIComponent::UCustomEmployeeAIComponent()
{
	APawn* Pawn = Cast<APawn>(GetOwner());
	//aiController = Cast<AAIController>(Pawn->GetController());
}
void UCustomEmployeeAIComponent::Patrol() {
	
}