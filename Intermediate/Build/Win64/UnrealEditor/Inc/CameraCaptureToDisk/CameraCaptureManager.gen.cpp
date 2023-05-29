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
	CAMERACAPTURETODISK_API UClass* Z_Construct_UClass_UCameraCaptureManager_NoRegister();
	CAMERACAPTURETODISK_API UClass* Z_Construct_UClass_UCameraCaptureManager();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent();
	ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
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
	DEFINE_FUNCTION(UCameraCaptureManager::execStartRTPS)
	{
		P_GET_UBOOL(Z_Param_bState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartRTPS(Z_Param_bState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCameraCaptureManager::execStartVideoRecord)
	{
		P_GET_UBOOL(Z_Param_bState);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartVideoRecord(Z_Param_bState);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCameraCaptureManager::execSetupCaptureComponent)
	{
		P_GET_OBJECT(USceneCaptureComponent2D,Z_Param_captureComponent);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetupCaptureComponent(Z_Param_captureComponent);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCameraCaptureManager::execMakeScreenShot)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->MakeScreenShot();
		P_NATIVE_END;
	}
	void UCameraCaptureManager::StaticRegisterNativesUCameraCaptureManager()
	{
		UClass* Class = UCameraCaptureManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MakeScreenShot", &UCameraCaptureManager::execMakeScreenShot },
			{ "SetupCaptureComponent", &UCameraCaptureManager::execSetupCaptureComponent },
			{ "StartRTPS", &UCameraCaptureManager::execStartRTPS },
			{ "StartVideoRecord", &UCameraCaptureManager::execStartVideoRecord },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCameraCaptureManager_MakeScreenShot_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCameraCaptureManager_MakeScreenShot_Statics::Function_MetaDataParams[] = {
		{ "Category", "ImageCapture" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCameraCaptureManager_MakeScreenShot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCameraCaptureManager, nullptr, "MakeScreenShot", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCameraCaptureManager_MakeScreenShot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraCaptureManager_MakeScreenShot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCameraCaptureManager_MakeScreenShot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCameraCaptureManager_MakeScreenShot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics
	{
		struct CameraCaptureManager_eventSetupCaptureComponent_Parms
		{
			USceneCaptureComponent2D* captureComponent;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_captureComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_captureComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::NewProp_captureComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::NewProp_captureComponent = { "captureComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CameraCaptureManager_eventSetupCaptureComponent_Parms, captureComponent), Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::NewProp_captureComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::NewProp_captureComponent_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::NewProp_captureComponent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "ImageCapture" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCameraCaptureManager, nullptr, "SetupCaptureComponent", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::CameraCaptureManager_eventSetupCaptureComponent_Parms), Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics
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
	void Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::NewProp_bState_SetBit(void* Obj)
	{
		((CameraCaptureManager_eventStartRTPS_Parms*)Obj)->bState = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::NewProp_bState = { "bState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CameraCaptureManager_eventStartRTPS_Parms), &Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::NewProp_bState_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::NewProp_bState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::Function_MetaDataParams[] = {
		{ "Category", "ImageCapture" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCameraCaptureManager, nullptr, "StartRTPS", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::CameraCaptureManager_eventStartRTPS_Parms), Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCameraCaptureManager_StartRTPS()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCameraCaptureManager_StartRTPS_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics
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
	void Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::NewProp_bState_SetBit(void* Obj)
	{
		((CameraCaptureManager_eventStartVideoRecord_Parms*)Obj)->bState = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::NewProp_bState = { "bState", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(CameraCaptureManager_eventStartVideoRecord_Parms), &Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::NewProp_bState_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::NewProp_bState,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::Function_MetaDataParams[] = {
		{ "Category", "ImageCapture" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCameraCaptureManager, nullptr, "StartVideoRecord", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::CameraCaptureManager_eventStartVideoRecord_Parms), Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCameraCaptureManager);
	UClass* Z_Construct_UClass_UCameraCaptureManager_NoRegister()
	{
		return UCameraCaptureManager::StaticClass();
	}
	struct Z_Construct_UClass_UCameraCaptureManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCameraCaptureManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USceneComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_CameraCaptureToDisk,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCameraCaptureManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCameraCaptureManager_MakeScreenShot, "MakeScreenShot" }, // 281878400
		{ &Z_Construct_UFunction_UCameraCaptureManager_SetupCaptureComponent, "SetupCaptureComponent" }, // 659996228
		{ &Z_Construct_UFunction_UCameraCaptureManager_StartRTPS, "StartRTPS" }, // 498951039
		{ &Z_Construct_UFunction_UCameraCaptureManager_StartVideoRecord, "StartVideoRecord" }, // 1796495585
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCameraCaptureManager_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "HideCategories", "Trigger PhysicsVolume" },
		{ "IncludePath", "CameraCaptureManager.h" },
		{ "ModuleRelativePath", "Public/CameraCaptureManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCameraCaptureManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCameraCaptureManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCameraCaptureManager_Statics::ClassParams = {
		&UCameraCaptureManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UCameraCaptureManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCameraCaptureManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCameraCaptureManager()
	{
		if (!Z_Registration_Info_UClass_UCameraCaptureManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCameraCaptureManager.OuterSingleton, Z_Construct_UClass_UCameraCaptureManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCameraCaptureManager.OuterSingleton;
	}
	template<> CAMERACAPTURETODISK_API UClass* StaticClass<UCameraCaptureManager>()
	{
		return UCameraCaptureManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCameraCaptureManager);
	struct Z_CompiledInDeferFile_FID_MyProject_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics::ScriptStructInfo[] = {
		{ FRenderRequestStruct::StaticStruct, Z_Construct_UScriptStruct_FRenderRequestStruct_Statics::NewStructOps, TEXT("RenderRequestStruct"), &Z_Registration_Info_UScriptStruct_RenderRequestStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRenderRequestStruct), 3085862693U) },
		{ FFloatRenderRequestStruct::StaticStruct, Z_Construct_UScriptStruct_FFloatRenderRequestStruct_Statics::NewStructOps, TEXT("FloatRenderRequestStruct"), &Z_Registration_Info_UScriptStruct_FloatRenderRequestStruct, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FFloatRenderRequestStruct), 1651365740U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCameraCaptureManager, UCameraCaptureManager::StaticClass, TEXT("UCameraCaptureManager"), &Z_Registration_Info_UClass_UCameraCaptureManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCameraCaptureManager), 3307210660U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_MyProject_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_3253715646(TEXT("/Script/CameraCaptureToDisk"),
		Z_CompiledInDeferFile_FID_MyProject_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_MyProject_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_MyProject_Plugins_CameraCaptureToDisk_Source_CameraCaptureToDisk_Public_CameraCaptureManager_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
