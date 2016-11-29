// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "S05_TestingGrounds.h"
#include "S05_TestingGroundsGameMode.h"
#include "S05_TestingGroundsHUD.h"
#include "Player/FirstPersonCharacter.h"

AS05_TestingGroundsGameMode::AS05_TestingGroundsGameMode()
	: Super()
{
	// Set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Dynamic/Player/Behaviour/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// Use our custom HUD class
	HUDClass = AS05_TestingGroundsHUD::StaticClass();
}
