// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ADnDGameMode.h"
#include "ADnDPlayerController.h"
#include "ADnDCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

AADnDGameMode::AADnDGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AADnDPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AADnDGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (UIWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), UIWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}