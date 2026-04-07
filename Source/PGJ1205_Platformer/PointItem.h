// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlatformerCollectable.h"
#include "PlatformerPlayerState.h"         
#include "GameFramework/PlayerController.h" 
#include "PointItem.generated.h"

/**
 * 
 */
UCLASS()
class PGJ1205_PLATFORMER_API APointItem : public APlatformerCollectable
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, Category="Collectable")
	int32 PointValue;

	virtual void OnCollected(AActor* OtherActor) override;

};
