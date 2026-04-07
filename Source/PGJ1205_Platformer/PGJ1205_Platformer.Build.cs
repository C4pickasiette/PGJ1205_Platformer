// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class PGJ1205_Platformer : ModuleRules
{
	public PGJ1205_Platformer(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
