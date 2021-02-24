// Copyright Epic Games, Inc. All Rights Reserved.

#include "GDTV_PuzzlePlatformsGameMode.h"
#include "GDTV_PuzzlePlatformsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGDTV_PuzzlePlatformsGameMode::AGDTV_PuzzlePlatformsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
