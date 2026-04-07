// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingComponent.h"
#include "RotationMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Platformer), meta = (BlueprintSpawnableComponent))
class PGJ1205_PLATFORMER_API URotationMovementComponent : public UMovingComponent
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, Category = "Movement")
	FRotator RotationRate;

	virtual void UpdateMovement(float DeltaTime) override;
};
