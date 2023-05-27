// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CameraCaptureToDisk/Public/CameraCaptureManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCameraCaptureManager() {}
// Cross Module References
	CAMERACAPTURETODISK_API UScriptStruct* Z_Construct_UScriptStruct_FRenderRequestStruct();
	UPackage* Z_Construct_UPackage__Script_CameraCaptureToDisk();
	CAMERACAPTURETODISK_API UScriptStruct* Z_Construct_UScriptStruct_FFloatRenderRequestStruct();
	CAMERACAPTURETODISK_API UClass* Z_Construct_UClass_ACameraCaptureManager_NoRegister();
	CAMERACAPTURETODISK_API UClass* Z_Construct_UClass_ACameraCaptureManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_ASceneCapture2D_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UMaterial_NoRegister();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_RenderRequestStruct;
class UScriptStruct* FRenderRequestStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_RenderRequestStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_RenderRequestStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRenderRequestStruct, Z_Construct_UPackage__Script_CameraCaptureToDisk(), TEXT("RenderRequestStruct"));
	}
	return Z_Registration_Info_UScriptStruct_RenderRequestStruct.OuterSingleton;
}
template<> CAMERACAPTURETODISK_API UScriptStruct* StaticStruct<FRenderRequestStruct>()
{
	return FRenderRequestStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FRenderRequestStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FRenderRequestStruct_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FRenderRequestStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRenderRequestStruct>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FRenderRequestStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_CameraCaptureToDisk,
		nullptr,
		&NewStructOps,
		"RenderRequestStruct",
		sizeof(FRenderRequestStruct),
		alignof(FRenderRequestStruct),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FRenderRequestStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FRenderRequestStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FRenderRequestStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_RenderRequestStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_RenderRequestStruct.InnerSingleton, Z_Construct_UScriptStruct_FRenderRequestStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_RenderRequestStruct.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FloatRenderRequestStruct;
class UScriptStruct* FFloatRenderRequestStruct::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FloatRenderRequestStruct.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FloatRenderRequestStruct.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FFloatRenderRequestStruct, Z_Construct_UPackage__Script_CameraCaptureToDisk(), TEXT("FloatRenderRequestStruct"));
	}
	return Z_Registration_Info_UScriptStruct_FloatRenderRequestStruct.OuterSingleton;
}
template<> CAMERACAPTURETODISK_API UScriptStruct* StaticStruct<FFloatRenderRequestStruct>()
{
	return FFloatRenderRequestStruct::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FFloatRenderRequestStruct_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FFloatRenderRequestStruct_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FFloatRenderRequestStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FFloatRenderRequestStruct>();
	}
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FFloatRenderRequestStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_CameraCaptureToDisk,
		nullptr,
		&NewStructOps,
		"FloatRenderRequestStruct",
		sizeof(FFloatRenderRequestStruct),
		alignof(FFloatRenderRequestStruct),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FFloatRenderRequestStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FFloatRenderRequestStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FFloatRenderRequestStruct()
	{
		if (!Z_Registration_Info_UScriptStruct_FloatRenderRequestStruct.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FloatRenderRequestStruct.InnerSingleton, Z_Construct_UScriptStruct_FFloatRenderRequestStruct_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_FloatRenderRequestStruct.InnerSingleton;
	}
	DEFINE_FUNCTION(ACameraCaptureManager::execStartRTPS)
	{
		P_GET_UBOOL(Z_Param_bState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartRTPS(Z_Param_bState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACameraCaptureManager::execStartVideoRecord)
	{
		P_GET_UBOOL(Z_Param_bState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartVideoRecord(Z_Param_bState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACameraCaptureManager::execSetupCaptureComponent)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetupCaptureComponent();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACameraCaptureManager::execMakeScreenShot)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MakeScreenShot();
		P_NATIVE_END;
	}
	void ACameraCaptureManager::StaticRegisterNativesACameraCaptureManager()
	{
		UClass* Class = ACameraCaptureManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MakeScreenShot", &ACameraCaptureManager::execMakeScreenShot },
			{ "SetupCaptureComponent", &ACameraCaptureManager::execSetupCaptureComponent },
			{ "StartRTPS", &ACameraCaptureManager::execStartRTPS },
			{ "StartVideoRecord", &ACameraCaptureManager::execStartVideoRecord },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ACameraCaptureManager_MakeScreenShot_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACameraCaptureManager_MakeScreenShot_Statics::Function_MetaDataParams[] = {
		{ "Category", "ImageCapture" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACameraCaptureManager_MakeScreenShot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACameraCaptureManager, nullptr, "MakeScreenShot", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACameraCaptureManager_MakeScreenShot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACameraCaptureManager_MakeScreenShot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACameraCaptureManager_MakeScreenShot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACameraCaptureManager_MakeScreenShot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACameraCaptureManager_SetupCaptureComponent_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACameraCaptureManager_SetupCaptureComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "ImageCapture" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACameraCaptureManager_SetupCaptureComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACameraCaptureManager, nullptr, "SetupCaptureComponent", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACameraCaptureManager_SetupCaptureComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACameraCaptureManager_SetupCaptureComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACameraCaptureManager_SetupCaptureComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACameraCaptureManager_SetupCaptureComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics
	{
		struct CameraCaptureManager_eventStartRTPS_Parms
		{
			bool bState;
		};
		static void NewProp_bState_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::NewProp_bState_SetBit(void* Obj)
	{
		((CameraCaptureManager_eventStartRTPS_Parms*)Obj)->bState = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::NewProp_bState = { "bState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CameraCaptureManager_eventStartRTPS_Parms), &Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::NewProp_bState_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::NewProp_bState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::Function_MetaDataParams[] = {
		{ "Category", "ImageCapture" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACameraCaptureManager, nullptr, "StartRTPS", nullptr, nullptr, sizeof(Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::CameraCaptureManager_eventStartRTPS_Parms), Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACameraCaptureManager_StartRTPS()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACameraCaptureManager_StartRTPS_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics
	{
		struct CameraCaptureManager_eventStartVideoRecord_Parms
		{
			bool bState;
		};
		static void NewProp_bState_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bState;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::NewProp_bState_SetBit(void* Obj)
	{
		((CameraCaptureManager_eventStartVideoRecord_Parms*)Obj)->bState = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::NewProp_bState = { "bState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CameraCaptureManager_eventStartVideoRecord_Parms), &Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::NewProp_bState_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::NewProp_bState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::Function_MetaDataParams[] = {
		{ "Category", "ImageCapture" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACameraCaptureManager, nullptr, "StartVideoRecord", nullptr, nullptr, sizeof(Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::CameraCaptureManager_eventStartVideoRecord_Parms), Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACameraCaptureManager);
	UClass* Z_Construct_UClass_ACameraCaptureManager_NoRegister()
	{
		return ACameraCaptureManager::StaticClass();
	}
	struct Z_Construct_UClass_ACameraCaptureManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SubDirectoryName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SubDirectoryName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrameWidth_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_FrameWidth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FrameHeight_MetaData[];
#endif
		static const UECodeGen_Private::FUnsizedIntPropertyParams NewProp_FrameHeight;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CaptureComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CaptureComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PostProcessMaterial_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_PostProcessMaterial;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VerboseLogging_MetaData[];
#endif
		static void NewProp_VerboseLogging_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_VerboseLogging;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACameraCaptureManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_CameraCaptureToDisk,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ACameraCaptureManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ACameraCaptureManager_MakeScreenShot, "MakeScreenShot" }, // 3371468997
		{ &Z_Construct_UFunction_ACameraCaptureManager_SetupCaptureComponent, "SetupCaptureComponent" }, // 3973803132
		{ &Z_Construct_UFunction_ACameraCaptureManager_StartRTPS, "StartRTPS" }, // 2359810662
		{ &Z_Construct_UFunction_ACameraCaptureManager_StartVideoRecord, "StartVideoRecord" }, // 2142202590
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACameraCaptureManager_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "CameraCaptureManager.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_SubDirectoryName_MetaData[] = {
		{ "Category", "Capture" },
		{ "Comment", "// Captured Data Sub-Directory Name \n" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
		{ "ToolTip", "Captured Data Sub-Directory Name" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_SubDirectoryName = { "SubDirectoryName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACameraCaptureManager, SubDirectoryName), METADATA_PARAMS(Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_SubDirectoryName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_SubDirectoryName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_FrameWidth_MetaData[] = {
		{ "Category", "Capture" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_FrameWidth = { "FrameWidth", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACameraCaptureManager, FrameWidth), METADATA_PARAMS(Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_FrameWidth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_FrameWidth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_FrameHeight_MetaData[] = {
		{ "Category", "Capture" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	const UECodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_FrameHeight = { "FrameHeight", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACameraCaptureManager, FrameHeight), METADATA_PARAMS(Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_FrameHeight_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_FrameHeight_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_CaptureComponent_MetaData[] = {
		{ "Category", "Capture" },
		{ "Comment", "// Color Capture Components\n" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
		{ "ToolTip", "Color Capture Components" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_CaptureComponent = { "CaptureComponent", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACameraCaptureManager, CaptureComponent), Z_Construct_UClass_ASceneCapture2D_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_CaptureComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_CaptureComponent_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_PostProcessMaterial_MetaData[] = {
		{ "Category", "Capture" },
		{ "Comment", "// PostProcessMaterial used for segmentation\n" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
		{ "ToolTip", "PostProcessMaterial used for segmentation" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_PostProcessMaterial = { "PostProcessMaterial", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACameraCaptureManager, PostProcessMaterial), Z_Construct_UClass_UMaterial_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_PostProcessMaterial_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_PostProcessMaterial_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_VerboseLogging_MetaData[] = {
		{ "Category", "Logging" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	void Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_VerboseLogging_SetBit(void* Obj)
	{
		((ACameraCaptureManager*)Obj)->VerboseLogging = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_VerboseLogging = { "VerboseLogging", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ACameraCaptureManager), &Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_VerboseLogging_SetBit, METADATA_PARAMS(Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_VerboseLogging_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_VerboseLogging_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACameraCaptureManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_SubDirectoryName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_FrameWidth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_FrameHeight,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_CaptureComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_PostProcessMaterial,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACameraCaptureManager_Statics::NewProp_VerboseLogging,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACameraCaptureManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACameraCaptureManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACameraCaptureManager_Statics::ClassParams = {
		&ACameraCaptureManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ACameraCaptureManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCaptureManager_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACameraCaptureManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACameraCaptureManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACameraCaptureManager()
	{
		if (!Z_Registration_Info_UClass_ACameraCaptureManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACameraCaptureManager.OuterSingleton, Z_Construct_UClass_ACameraCaptureManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACameraCaptureManager.OuterSingleton;
	}
	template<> CAMERACAPTURETODISK_API UClass* StaticClass<ACameraCaptureManager>()
	{
		return ACameraCaptureManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACameraCaptureManager);
	struct Z_CompiledInDeferFile_FID_CaptureToDisk_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CaptureToDisk_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics::ScriptStructInfo[] = {
		{ FRenderRequestStruct::StaticStruct, Z_Construct_UScriptStruct_FRenderRequestStruct_Statics::NewStructOps, TEXT("RenderRequestStruct"), &Z_Registration_Info_UScriptStruct_RenderRequestStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRenderRequestStruct), 3085862693U) },
		{ FFloatRenderRequestStruct::StaticStruct, Z_Construct_UScriptStruct_FFloatRenderRequestStruct_Statics::NewStructOps, TEXT("FloatRenderRequestStruct"), &Z_Registration_Info_UScriptStruct_FloatRenderRequestStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFloatRenderRequestStruct), 1651365740U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CaptureToDisk_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACameraCaptureManager, ACameraCaptureManager::StaticClass, TEXT("ACameraCaptureManager"), &Z_Registration_Info_UClass_ACameraCaptureManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACameraCaptureManager), 1345912639U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_CaptureToDisk_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_455164438(TEXT("/Script/CameraCaptureToDisk"),
		Z_CompiledInDeferFile_FID_CaptureToDisk_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CaptureToDisk_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_CaptureToDisk_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_CaptureToDisk_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
