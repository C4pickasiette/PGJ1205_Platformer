// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameOverWidget.h"
#include "EndGameWidget.h"
#include "InGameWidget.h"
#include "PGJ1205_PlatformerGameMode.h"
#include "PlatformerHUD.generated.h"

/**
 * 
 */
UCLASS()
class PGJ1205_PLATFORMER_API APlatformerHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UInGameWidget> InGameWidgetBP;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UGameOverWidget> GameOverWidgetBP;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UEndGameWidget> EndGameWidgetBP;

	UFUNCTION()
	void UpdatePoint(int32 NewPoint);

	UFUNCTION()
	void UpdateTime(float NewTime);

	UFUNCTION()
	void ShowEndGame(float FinalTime, int32 FinalPoints);

	UFUNCTION()
	void ShowGameOver();

private:
	UPROPERTY()
	UInGameWidget* InGameWidget;

	UPROPERTY()
	UGameOverWidget* GameOverWidget;

	UPROPERTY()
	UEndGameWidget* EndGameWidget;
};
