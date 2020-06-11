// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RogueLike3DGameMode.h"
#include "RogueLike3DCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARogueLike3DGameMode::ARogueLike3DGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
