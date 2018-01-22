// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Leviathan.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLeviathan() {}
// Cross Module References
	ROBOSUB_UNREAL_API UClass* Z_Construct_UClass_ALeviathan_NoRegister();
	ROBOSUB_UNREAL_API UClass* Z_Construct_UClass_ALeviathan();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_robosub_unreal();
// End Cross Module References
	void ALeviathan::StaticRegisterNativesALeviathan()
	{
	}
	UClass* Z_Construct_UClass_ALeviathan_NoRegister()
	{
		return ALeviathan::StaticClass();
	}
	UClass* Z_Construct_UClass_ALeviathan()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_APawn,
				(UObject* (*)())Z_Construct_UPackage__Script_robosub_unreal,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Navigation" },
				{ "IncludePath", "Leviathan.h" },
				{ "ModuleRelativePath", "Leviathan.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_movementSpeed_MetaData[] = {
				{ "Category", "Sub" },
				{ "ModuleRelativePath", "Leviathan.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_movementSpeed = { UE4CodeGen_Private::EPropertyClass::Float, "movementSpeed", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ALeviathan, movementSpeed), METADATA_PARAMS(NewProp_movementSpeed_MetaData, ARRAY_COUNT(NewProp_movementSpeed_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_movementSpeed,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ALeviathan>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ALeviathan::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ALeviathan, 852815185);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ALeviathan(Z_Construct_UClass_ALeviathan, &ALeviathan::StaticClass, TEXT("/Script/robosub_unreal"), TEXT("ALeviathan"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ALeviathan);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
