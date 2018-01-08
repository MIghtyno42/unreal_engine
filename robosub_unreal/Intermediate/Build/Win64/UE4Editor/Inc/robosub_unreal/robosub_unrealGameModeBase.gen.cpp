// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "robosub_unrealGameModeBase.h"
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
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_robosub_unreal,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "robosub_unrealGameModeBase.h" },
				{ "ModuleRelativePath", "robosub_unrealGameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<Arobosub_unrealGameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&Arobosub_unrealGameModeBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Arobosub_unrealGameModeBase, 2871634013);
	static FCompiledInDefer Z_CompiledInDefer_UClass_Arobosub_unrealGameModeBase(Z_Construct_UClass_Arobosub_unrealGameModeBase, &Arobosub_unrealGameModeBase::StaticClass, TEXT("/Script/robosub_unreal"), TEXT("Arobosub_unrealGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Arobosub_unrealGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
