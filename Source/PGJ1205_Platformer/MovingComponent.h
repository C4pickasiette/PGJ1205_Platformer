// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MovingComponent.generated.h"


UCLASS(abstract, ClassGroup=(Platformer), meta=(BlueprintSpawnableComponent) )
class PGJ1205_PLATFORMER_API UMovingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovingComponent();

protected:
	virtual void UpdateMovement(float DeltaTime);

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Speed = 1;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
