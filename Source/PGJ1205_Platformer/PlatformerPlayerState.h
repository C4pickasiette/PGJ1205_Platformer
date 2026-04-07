// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PGJ1205_PlatformerGameMode.h"
#include "PlatformerPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PGJ1205_PLATFORMER_API APlatformerPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platformer")
	int32 PlayerScore = 0;

	void AddScore(int32 Amount);
};
