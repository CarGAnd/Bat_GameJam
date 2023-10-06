// Fill out your copyright notice in the Description page of Project Settings.


#include "Audio_BatCall_GlobalState.h"

void UAudio_BatCall_GlobalState::AmbienceDimVolume(UFMODBus* Bus)
{
	UFMODBlueprintStatics::BusSetVolume(Bus, 0.1);
}