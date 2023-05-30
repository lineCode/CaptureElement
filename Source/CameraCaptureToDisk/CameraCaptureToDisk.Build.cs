// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;
using System.Text.RegularExpressions;
using UnrealBuildTool;

public class CameraCaptureToDisk : ModuleRules
{
	private string ModulePath
	{
		get { return ModuleDirectory; }
	}
	private string ThirdPartyPath
	{
		get { return Path.GetFullPath(Path.Combine(ModulePath, "../ThirdParty/")); }
	}
	private string BinariesPath
	{
		get { return Path.GetFullPath(Path.Combine(ModulePath, "../../Binaries/")); }
	}



	public CameraCaptureToDisk(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicAdditionalLibraries.Add(Path.Combine(ThirdPartyPath, "openh264/lib/openh264.lib"));
		PublicIncludePaths.Add(Path.Combine(ThirdPartyPath, "openh264/include"));

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);
		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"InputCore", 
				"ImageWrapper", 
				"RenderCore", 
				"Renderer", 
				"RHI",
				"OpenCV", "OpenCVHelper"
				// ... add other public dependencies that you statically link with here ...
			}
			);
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
			);
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
