// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Classes/FMODPort.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFMODPort() {}
// Cross Module References
	FMODSTUDIO_API UClass* Z_Construct_UClass_UFMODAsset();
	FMODSTUDIO_API UClass* Z_Construct_UClass_UFMODPort();
	FMODSTUDIO_API UClass* Z_Construct_UClass_UFMODPort_NoRegister();
	UPackage* Z_Construct_UPackage__Script_FMODStudio();
// End Cross Module References
	void UFMODPort::StaticRegisterNativesUFMODPort()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFMODPort);
	UClass* Z_Construct_UClass_UFMODPort_NoRegister()
	{
		return UFMODPort::StaticClass();
	}
	struct Z_Construct_UClass_UFMODPort_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFMODPort_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFMODAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_FMODStudio,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFMODPort_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFMODPort_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * FMOD Port Asset.\n */" },
#endif
		{ "IncludePath", "FMODPort.h" },
		{ "ModuleRelativePath", "Classes/FMODPort.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FMOD Port Asset." },
#endif
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFMODPort_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFMODPort>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UFMODPort_Statics::ClassParams = {
		&UFMODPort::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFMODPort_Statics::Class_MetaDataParams), Z_Construct_UClass_UFMODPort_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UFMODPort()
	{
		if (!Z_Registration_Info_UClass_UFMODPort.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFMODPort.OuterSingleton, Z_Construct_UClass_UFMODPort_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UFMODPort.OuterSingleton;
	}
	template<> FMODSTUDIO_API UClass* StaticClass<UFMODPort>()
	{
		return UFMODPort::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFMODPort);
	UFMODPort::~UFMODPort() {}
	struct Z_CompiledInDeferFile_FID_Users_Nenn_Documents_Unreal_Projects_Bat_GameJam_Plugins_FMODStudio_Source_FMODStudio_Classes_FMODPort_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Nenn_Documents_Unreal_Projects_Bat_GameJam_Plugins_FMODStudio_Source_FMODStudio_Classes_FMODPort_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UFMODPort, UFMODPort::StaticClass, TEXT("UFMODPort"), &Z_Registration_Info_UClass_UFMODPort, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFMODPort), 3650777053U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_Nenn_Documents_Unreal_Projects_Bat_GameJam_Plugins_FMODStudio_Source_FMODStudio_Classes_FMODPort_h_3591740949(TEXT("/Script/FMODStudio"),
		Z_CompiledInDeferFile_FID_Users_Nenn_Documents_Unreal_Projects_Bat_GameJam_Plugins_FMODStudio_Source_FMODStudio_Classes_FMODPort_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_Nenn_Documents_Unreal_Projects_Bat_GameJam_Plugins_FMODStudio_Source_FMODStudio_Classes_FMODPort_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
