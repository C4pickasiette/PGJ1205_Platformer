// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformerCollectable.h"
#include "PGJ1205_PlatformerCharacter.h"
#include "PowerUpItem.generated.h"

/**
 * 
 */
UCLASS()
class PGJ1205_PLATFORMER_API APowerUpItem : public APlatformerCollectable
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Power Up")
	float Duration;

	UPROPERTY(EditAnywhere, Category = "Power Up")
	float SpeedMultiplier;

	UPROPERTY(EditAnywhere, Category = "Power Up")
	float JumpMultiplier;

	
protected:
	virtual void OnCollected(AActor* OtherActor) override;
};
