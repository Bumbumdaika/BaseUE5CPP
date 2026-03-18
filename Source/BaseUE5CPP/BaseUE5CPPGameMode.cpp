// Copyright Epic Games, Inc. All Rights Reserved.

#include "BaseUE5CPPGameMode.h"
#include "BaseUE5CPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABaseUE5CPPGameMode::ABaseUE5CPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
