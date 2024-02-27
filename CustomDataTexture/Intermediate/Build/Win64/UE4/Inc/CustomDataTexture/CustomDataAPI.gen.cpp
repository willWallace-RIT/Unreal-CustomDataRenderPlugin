// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomDataTexture/Classes/CustomDataAPI.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomDataAPI() {}
// Cross Module References
	CUSTOMDATATEXTURE_API UScriptStruct* Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel();
	UPackage* Z_Construct_UPackage__Script_CustomDataTexture();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FMatrix();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
// End Cross Module References
class UScriptStruct* FCustomDataTextureGenerationModel::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern CUSTOMDATATEXTURE_API uint32 Get_Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel, Z_Construct_UPackage__Script_CustomDataTexture(), TEXT("CustomDataTextureGenerationModel"), sizeof(FCustomDataTextureGenerationModel), Get_Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Hash());
	}
	return Singleton;
}
template<> CUSTOMDATATEXTURE_API UScriptStruct* StaticStruct<FCustomDataTextureGenerationModel>()
{
	return FCustomDataTextureGenerationModel::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FCustomDataTextureGenerationModel(FCustomDataTextureGenerationModel::StaticStruct, TEXT("/Script/CustomDataTexture"), TEXT("CustomDataTextureGenerationModel"), false, nullptr, nullptr);
static struct FScriptStruct_CustomDataTexture_StaticRegisterNativesFCustomDataTextureGenerationModel
{
	FScriptStruct_CustomDataTexture_StaticRegisterNativesFCustomDataTextureGenerationModel()
	{
		UScriptStruct::DeferCppStructOps<FCustomDataTextureGenerationModel>(FName(TEXT("CustomDataTextureGenerationModel")));
	}
} ScriptStruct_CustomDataTexture_StaticRegisterNativesFCustomDataTextureGenerationModel;
	struct Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_VIEWMATRIX_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_VIEWMATRIX;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PROJMATRIX_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PROJMATRIX;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Actors_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Actors_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Actors;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_renderTarget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_renderTarget;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Classes/CustomDataAPI.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCustomDataTextureGenerationModel>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_VIEWMATRIX_MetaData[] = {
		{ "Category", "CustomDataTexture" },
		{ "ModuleRelativePath", "Classes/CustomDataAPI.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_VIEWMATRIX = { "VIEWMATRIX", nullptr, (EPropertyFlags)0x0010000200000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCustomDataTextureGenerationModel, VIEWMATRIX), Z_Construct_UScriptStruct_FMatrix, METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_VIEWMATRIX_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_VIEWMATRIX_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_PROJMATRIX_MetaData[] = {
		{ "Category", "CustomDataTexture" },
		{ "ModuleRelativePath", "Classes/CustomDataAPI.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_PROJMATRIX = { "PROJMATRIX", nullptr, (EPropertyFlags)0x0010000200000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCustomDataTextureGenerationModel, PROJMATRIX), Z_Construct_UScriptStruct_FMatrix, METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_PROJMATRIX_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_PROJMATRIX_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_Actors_Inner = { "Actors", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_Actors_MetaData[] = {
		{ "Category", "CustomDataTexture" },
		{ "ModuleRelativePath", "Classes/CustomDataAPI.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_Actors = { "Actors", nullptr, (EPropertyFlags)0x0010000200000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCustomDataTextureGenerationModel, Actors), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_Actors_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_Actors_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_renderTarget_MetaData[] = {
		{ "Category", "CustomDataTexture" },
		{ "ModuleRelativePath", "Classes/CustomDataAPI.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_renderTarget = { "renderTarget", nullptr, (EPropertyFlags)0x0010000200000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCustomDataTextureGenerationModel, renderTarget), Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_renderTarget_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_renderTarget_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_VIEWMATRIX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_PROJMATRIX,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_Actors_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_Actors,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::NewProp_renderTarget,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_CustomDataTexture,
		nullptr,
		&NewStructOps,
		"CustomDataTextureGenerationModel",
		sizeof(FCustomDataTextureGenerationModel),
		alignof(FCustomDataTextureGenerationModel),
		Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_CustomDataTexture();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("CustomDataTextureGenerationModel"), sizeof(FCustomDataTextureGenerationModel), Get_Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel_Hash() { return 2008522274U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
