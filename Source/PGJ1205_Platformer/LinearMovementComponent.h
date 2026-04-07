// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingComponent.h"
#include "LinearMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Platformer), meta = (BlueprintSpawnableComponent))
class PGJ1205_PLATFORMER_API ULinearMovementComponent : public UMovingComponent
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector Axis;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Amplitude;

	virtual void BeginPlay() override;
	virtual void UpdateMovement(float DeltaTime) override;

private:
	FVector StartLocation;
	float ElapsedTime;
};
