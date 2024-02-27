// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CustomDataTexture/Classes/CustomDataBlueprintLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCustomDataBlueprintLibrary() {}
// Cross Module References
	CUSTOMDATATEXTURE_API UClass* Z_Construct_UClass_UCustomDataBlueprintLibrary_NoRegister();
	CUSTOMDATATEXTURE_API UClass* Z_Construct_UClass_UCustomDataBlueprintLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_CustomDataTexture();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	CUSTOMDATATEXTURE_API UScriptStruct* Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel();
// End Cross Module References
	DEFINE_FUNCTION(UCustomDataBlueprintLibrary::execNotEqual_CompareCustomDataTextureGenerationModels)
	{
		P_GET_STRUCT_REF(FCustomDataTextureGenerationModel,Z_Param_Out_A);
		P_GET_STRUCT_REF(FCustomDataTextureGenerationModel,Z_Param_Out_B);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UCustomDataBlueprintLibrary::NotEqual_CompareCustomDataTextureGenerationModels(Z_Param_Out_A,Z_Param_Out_B);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomDataBlueprintLibrary::execEqualEqual_CompareLensDistortionModels)
	{
		P_GET_STRUCT_REF(FCustomDataTextureGenerationModel,Z_Param_Out_A);
		P_GET_STRUCT_REF(FCustomDataTextureGenerationModel,Z_Param_Out_B);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UCustomDataBlueprintLibrary::EqualEqual_CompareLensDistortionModels(Z_Param_Out_A,Z_Param_Out_B);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCustomDataBlueprintLibrary::execDrawGeometryToRenderTarget)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_STRUCT_REF(FCustomDataTextureGenerationModel,Z_Param_Out_model);
		P_FINISH;
		P_NATIVE_BEGIN;
		UCustomDataBlueprintLibrary::DrawGeometryToRenderTarget(Z_Param_WorldContextObject,Z_Param_Out_model);
		P_NATIVE_END;
	}
	void UCustomDataBlueprintLibrary::StaticRegisterNativesUCustomDataBlueprintLibrary()
	{
		UClass* Class = UCustomDataBlueprintLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DrawGeometryToRenderTarget", &UCustomDataBlueprintLibrary::execDrawGeometryToRenderTarget },
			{ "EqualEqual_CompareLensDistortionModels", &UCustomDataBlueprintLibrary::execEqualEqual_CompareLensDistortionModels },
			{ "NotEqual_CompareCustomDataTextureGenerationModels", &UCustomDataBlueprintLibrary::execNotEqual_CompareCustomDataTextureGenerationModels },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics
	{
		struct CustomDataBlueprintLibrary_eventDrawGeometryToRenderTarget_Parms
		{
			const UObject* WorldContextObject;
			FCustomDataTextureGenerationModel model;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WorldContextObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_model;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::NewProp_WorldContextObject_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomDataBlueprintLibrary_eventDrawGeometryToRenderTarget_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::NewProp_WorldContextObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::NewProp_WorldContextObject_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::NewProp_model = { "model", nullptr, (EPropertyFlags)0x0010000008000180, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomDataBlueprintLibrary_eventDrawGeometryToRenderTarget_Parms, model), Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::NewProp_WorldContextObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::NewProp_model,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::Function_MetaDataParams[] = {
		{ "Category", "CustomDataTexture" },
		{ "ModuleRelativePath", "Classes/CustomDataBlueprintLibrary.h" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomDataBlueprintLibrary, nullptr, "DrawGeometryToRenderTarget", nullptr, nullptr, sizeof(CustomDataBlueprintLibrary_eventDrawGeometryToRenderTarget_Parms), Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics
	{
		struct CustomDataBlueprintLibrary_eventEqualEqual_CompareLensDistortionModels_Parms
		{
			FCustomDataTextureGenerationModel A;
			FCustomDataTextureGenerationModel B;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_A;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_B;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_A_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomDataBlueprintLibrary_eventEqualEqual_CompareLensDistortionModels_Parms, A), Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel, METADATA_PARAMS(Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_A_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_A_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_B_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomDataBlueprintLibrary_eventEqualEqual_CompareLensDistortionModels_Parms, B), Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel, METADATA_PARAMS(Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_B_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_B_MetaData)) };
	void Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CustomDataBlueprintLibrary_eventEqualEqual_CompareLensDistortionModels_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CustomDataBlueprintLibrary_eventEqualEqual_CompareLensDistortionModels_Parms), &Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_A,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_B,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::Function_MetaDataParams[] = {
		{ "Category", "CustomDataTexture" },
		{ "CompactNodeTitle", "==" },
		{ "DisplayName", "Equal (CustomDataTextureGenerationModel)" },
		{ "Keywords", "== equal" },
		{ "ModuleRelativePath", "Classes/CustomDataBlueprintLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomDataBlueprintLibrary, nullptr, "EqualEqual_CompareLensDistortionModels", nullptr, nullptr, sizeof(CustomDataBlueprintLibrary_eventEqualEqual_CompareLensDistortionModels_Parms), Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics
	{
		struct CustomDataBlueprintLibrary_eventNotEqual_CompareCustomDataTextureGenerationModels_Parms
		{
			FCustomDataTextureGenerationModel A;
			FCustomDataTextureGenerationModel B;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_A_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_A;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_B_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_B;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_A_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_A = { "A", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomDataBlueprintLibrary_eventNotEqual_CompareCustomDataTextureGenerationModels_Parms, A), Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel, METADATA_PARAMS(Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_A_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_A_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_B_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_B = { "B", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CustomDataBlueprintLibrary_eventNotEqual_CompareCustomDataTextureGenerationModels_Parms, B), Z_Construct_UScriptStruct_FCustomDataTextureGenerationModel, METADATA_PARAMS(Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_B_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_B_MetaData)) };
	void Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CustomDataBlueprintLibrary_eventNotEqual_CompareCustomDataTextureGenerationModels_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CustomDataBlueprintLibrary_eventNotEqual_CompareCustomDataTextureGenerationModels_Parms), &Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_A,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_B,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::Function_MetaDataParams[] = {
		{ "Category", "CustomDataTextureGeneration" },
		{ "CompactNodeTitle", "!=" },
		{ "DisplayName", "NotEqual (CustomDataTextureGenerationModel)" },
		{ "Keywords", "!= not equal" },
		{ "ModuleRelativePath", "Classes/CustomDataBlueprintLibrary.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCustomDataBlueprintLibrary, nullptr, "NotEqual_CompareCustomDataTextureGenerationModels", nullptr, nullptr, sizeof(CustomDataBlueprintLibrary_eventNotEqual_CompareCustomDataTextureGenerationModels_Parms), Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCustomDataBlueprintLibrary_NoRegister()
	{
		return UCustomDataBlueprintLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UCustomDataBlueprintLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCustomDataBlueprintLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_CustomDataTexture,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCustomDataBlueprintLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCustomDataBlueprintLibrary_DrawGeometryToRenderTarget, "DrawGeometryToRenderTarget" }, // 242020673
		{ &Z_Construct_UFunction_UCustomDataBlueprintLibrary_EqualEqual_CompareLensDistortionModels, "EqualEqual_CompareLensDistortionModels" }, // 327348041
		{ &Z_Construct_UFunction_UCustomDataBlueprintLibrary_NotEqual_CompareCustomDataTextureGenerationModels, "NotEqual_CompareCustomDataTextureGenerationModels" }, // 112092807
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCustomDataBlueprintLibrary_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CustomDataBlueprintLibrary.h" },
		{ "ModuleRelativePath", "Classes/CustomDataBlueprintLibrary.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCustomDataBlueprintLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCustomDataBlueprintLibrary>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UCustomDataBlueprintLibrary_Statics::ClassParams = {
		&UCustomDataBlueprintLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x000800A0u,
		METADATA_PARAMS(Z_Construct_UClass_UCustomDataBlueprintLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCustomDataBlueprintLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCustomDataBlueprintLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UCustomDataBlueprintLibrary_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCustomDataBlueprintLibrary, 2219370434);
	template<> CUSTOMDATATEXTURE_API UClass* StaticClass<UCustomDataBlueprintLibrary>()
	{
		return UCustomDataBlueprintLibrary::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCustomDataBlueprintLibrary(Z_Construct_UClass_UCustomDataBlueprintLibrary, &UCustomDataBlueprintLibrary::StaticClass, TEXT("/Script/CustomDataTexture"), TEXT("UCustomDataBlueprintLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCustomDataBlueprintLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
