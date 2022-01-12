// Copyright Epic Games, Inc. All Rights Reserved.

#include "V5GameMode.h"
#include "V5HUD.h"
#include "V5Character.h"
#include "UObject/ConstructorHelpers.h"

AV5GameMode::AV5GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AV5HUD::StaticClass();
}
