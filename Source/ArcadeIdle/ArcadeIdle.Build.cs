// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ArcadeIdle : ModuleRules
{
	public ArcadeIdle(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Niagara", "EnhancedInput", "AIModule", "UMG" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[] 
		{ 
			"ArcadeIdle/Public/UI",
			"ArcadeIdle/Public/Character",
			"ArcadeIdle/Public/Dev"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
