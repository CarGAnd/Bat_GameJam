// Fill out your copyright notice in the Description page of Project Settings.

#include "AudioUtilities.h"

void UAudioUtilities::PrintHello()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello World!"));
}

void UAudioUtilities::PlayOneShotEvent2D(UFMODEvent* myEvent)
{
	UFMODBlueprintStatics::PlayEvent2D(nullptr, myEvent, true);
}

// conversion function so volume can be set by logarithmic dB scaling
float UAudioUtilities::dBToLinear(float dB)
{
	return pow(10.0f, dB / 20.0f);
}

// Set MasterVolumeVCA
FMOD::Studio::VCA* masterVca;

void UAudioUtilities::SetMasterVolume(float dbVolume)
{
	UPROPERTY(EditAnywhere, Category = "FMOD", meta = (ClampMin = "-80", ClampMax = "10"))
	float masterVolume = dbVolume;

	if (IFMODStudioModule::IsAvailable())
	{
		FMOD::Studio::System* StudioSystem = IFMODStudioModule::Get().GetStudioSystem(EFMODSystemContext::Runtime);
		if (StudioSystem)
		{
			StudioSystem->getVCA(TCHAR_TO_UTF8(*FName("vca:/VCA_MASTER").ToString()), &masterVca);
		}
	}
	masterVca->setVolume(dBToLinear(masterVolume));
}

// Set VCAs
void UAudioUtilities::SetVcaVolume(UFMODVCA* vca, float dbVolume)
{
	UFMODBlueprintStatics::VCASetVolume(vca, dBToLinear(dbVolume));
}