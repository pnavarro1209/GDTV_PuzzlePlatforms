// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GDTV_PuzzlePlatformsTarget : TargetRules
{
	public GDTV_PuzzlePlatformsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("GDTV_PuzzlePlatforms");
	}
}
