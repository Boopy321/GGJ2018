// Fill out your copyright notice in the Description page of Project Settings.

#include "GGJ2018.h"
#include "HP_GameMode.h"
#include "HP_CharacterBase.h"

AHP_GameMode::AHP_GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/HotPockets/BP_CharacterBase"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}

