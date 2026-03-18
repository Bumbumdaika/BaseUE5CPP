// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BaseUE5CPP : ModuleRules
{
	public BaseUE5CPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AIModule"});
	}
}
