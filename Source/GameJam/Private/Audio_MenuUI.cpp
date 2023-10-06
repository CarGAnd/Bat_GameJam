// Fill out your copyright notice in the Description page of Project Settings.


#include "Audio_MenuUI.h"

void UAudio_MenuUI::SetMasterVolume(UFMODVCA* MasterVca, float Volume)
{
	UFMODBlueprintStatics::VCASetVolume(MasterVca, Volume);
}