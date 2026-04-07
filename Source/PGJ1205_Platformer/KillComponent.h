// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PGJ1205_PlatformerCharacter.h"
#include "KillComponent.generated.h"


UCLASS( ClassGroup=(Platformer), meta=(BlueprintSpawnableComponent) )
class PGJ1205_PLATFORMER_API UKillComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UKillComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse,	const FHitResult& Hit);
};
