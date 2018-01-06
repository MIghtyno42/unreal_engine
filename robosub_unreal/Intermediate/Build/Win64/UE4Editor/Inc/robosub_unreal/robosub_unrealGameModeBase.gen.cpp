// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "robosub_unrealGameModeBase.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCoderobosub_unrealGameModeBase() {}
// Cross Module References
	ROBOSUB_UNREAL_API UClass* Z_Construct_UClass_Arobosub_unrealGameModeBase_NoRegister();
	ROBOSUB_UNREAL_API UClass* Z_Construct_UClass_Arobosub_unrealGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_robosub_unreal();
// End Cross Module References
	void Arobosub_unrealGameModeBase::StaticRegisterNativesArobosub_unrealGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_Arobosub_unrealGameModeBase_NoRegister()
	{
		return Arobosub_unrealGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_Arobosub_unrealGameModeBase()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AGameModeBase();
			Z_Construct_UPackage__Script_robosub_unreal();
			OuterClass = Arobosub_unrealGameModeBase::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900288u;


				static TCppClassTypeInfo<TCppClassTypeTraits<Arobosub_unrealGameModeBase> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("robosub_unrealGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("robosub_unrealGameModeBase.h"));
				MetaData->SetValue(OuterClass, TEXT("ShowCategories"), TEXT("Input|MouseInput Input|TouchInput"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(Arobosub_unrealGameModeBase, 2130897759);
	static FCompiledInDefer Z_CompiledInDefer_UClass_Arobosub_unrealGameModeBase(Z_Construct_UClass_Arobosub_unrealGameModeBase, &Arobosub_unrealGameModeBase::StaticClass, TEXT("/Script/robosub_unreal"), TEXT("Arobosub_unrealGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Arobosub_unrealGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
