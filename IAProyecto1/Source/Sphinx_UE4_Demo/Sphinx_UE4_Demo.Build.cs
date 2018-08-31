// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Sphinx_UE4_Demo : ModuleRules
{
	public Sphinx_UE4_Demo(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "SpeechRecognition" });


        PrivateDependencyModuleNames.AddRange(new string[] { });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
