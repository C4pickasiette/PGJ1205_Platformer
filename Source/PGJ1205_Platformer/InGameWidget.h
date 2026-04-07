// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InGameWidget.generated.h"

/**
 * 
 */
UCLASS()
class PGJ1205_PLATFORMER_API UInGameWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category = "InGame")
	void OnPointsUpdated(int32 NewPoints);

	UFUNCTION(BlueprintImplementableEvent, Category = "InGame")
	void OnTimeUpdated(float NewTime);
};
