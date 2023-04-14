// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TDCoinCollector : ModuleRules
{
	public TDCoinCollector(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule", "Niagara" });
    }
}
