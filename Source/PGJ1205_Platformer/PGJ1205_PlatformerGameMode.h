// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PGJ1205_PlatformerGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPointsChanged, int32, NewPoints);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimerUpdated, float, ElapsedTime);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDied);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLevelFinished, float, FinalTime, int32, FinalScore);



UCLASS(minimalapi)
class APGJ1205_PlatformerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APGJ1205_PlatformerGameMode();

	void OnPlayerDied();

	void StartTimer();
	void StopTimer();
	float GetElapsedTime() const;
	void NotifyPointsChanged(int32 NewPoints);

	UPROPERTY(BlueprintAssignable)
	FOnPointsChanged OnPointsChanged;

	UPROPERTY(BlueprintAssignable)
	FOnTimerUpdated OnTimerUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerDied OnPlayerDiedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnLevelFinished OnLevelFinished;

protected:
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle DeathTimerHandle;

	void RestartLevel();

	float ElapsedTime;
	bool bTimer;
};



