// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class GDTV_PuzzlePlatformsEditorTarget : TargetRules
{
	public GDTV_PuzzlePlatformsEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("GDTV_PuzzlePlatforms");
	}
}
