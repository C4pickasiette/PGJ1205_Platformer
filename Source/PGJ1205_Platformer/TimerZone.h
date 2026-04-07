// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "PGJ1205_PlatformerCharacter.h"
#include "PGJ1205_PlatformerGameMode.h"
#include "TimerZone.generated.h"

UENUM(BlueprintType)
enum class TimeZoneType : uint8
{
	Start	UMETA(DisplayName = "Start"),
	End		UMETA(DisplayName = "End")
};

UCLASS()
class PGJ1205_PLATFORMER_API ATimerZone : public ATriggerBox
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

public:
	UPROPERTY(EditAnywhere, Category = "Settings")
	TimeZoneType ZoneType;
};
