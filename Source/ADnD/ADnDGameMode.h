// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Core.h"
#include "GameFramework/GameModeBase.h"
#include "ADnDGameMode.generated.h"

UCLASS(minimalapi)
class AADnDGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AADnDGameMode();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", Meta = (BlueprintProtected = "true"))
	TSubclassOf<class UUserWidget> UIWidgetClass;

	UPROPERTY()
	class UUserWidget* CurrentWidget;
};



