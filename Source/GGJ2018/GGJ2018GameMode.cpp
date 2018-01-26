// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "GGJ2018.h"
#include "GGJ2018GameMode.h"
#include "GGJ2018HUD.h"
#include "GGJ2018Character.h"

AGGJ2018GameMode::AGGJ2018GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGGJ2018HUD::StaticClass();
}
