// Fill out your copyright notice in the Description page of Project Settings.


#include "Audio_BatCall_GlobalState.h"

void UAudio_BatCall_GlobalState::AmbienceDimVolume(UFMODBus* Bus)
{
	UFMODBlueprintStatics::BusSetVolume(Bus, 0.1);
}

void UAudio_BatCall_GlobalState::BatCallExecMain(UFMODBus* Bus, float DelSec)
{
	// Call Event

	// Turn Snapshot on

	// Press keyoff after x seconds

	// Reverb modify
}

void UAudio_BatCall_GlobalState::BatCallExecV2(UFMODBus* Bus)
{
	// Call Event

	// Turn Snapshot on

	// Press keyoff after 5 seconds

	// Reverb modify
}