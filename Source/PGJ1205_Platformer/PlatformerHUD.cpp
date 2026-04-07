// Fill out your copyright notice in the Description page of Project Settings.


#include "Kismet/GameplayStatics.h"
#include "PlatformerHUD.h"

void APlatformerHUD::BeginPlay()
{
	Super::BeginPlay();

	if (!InGameWidgetBP || !GameOverWidgetBP || !EndGameWidgetBP)
		return;

	InGameWidget = CreateWidget<UInGameWidget>(GetWorld(), InGameWidgetBP);
	if (InGameWidget)
		InGameWidget->AddToViewport();

	GameOverWidget = CreateWidget<UGameOverWidget>(GetWorld(), GameOverWidgetBP);
	EndGameWidget = CreateWidget<UEndGameWidget>(GetWorld(), EndGameWidgetBP);

	if (APGJ1205_PlatformerGameMode* GM = Cast<APGJ1205_PlatformerGameMode>(UGameplayStatics::GetGameMode(this)))
	{
		GM->OnPointsChanged.AddDynamic(this, &APlatformerHUD::UpdatePoint);
		GM->OnTimerUpdated.AddDynamic(this, &APlatformerHUD::UpdateTime);
		GM->OnPlayerDiedDelegate.AddDynamic(this, &APlatformerHUD::ShowGameOver);
		GM->OnLevelFinished.AddDynamic(this, &APlatformerHUD::ShowEndGame);
	}
}

void APlatformerHUD::UpdatePoint(int32 NewPoint)
{
	if (InGameWidget)
	{
		InGameWidget->OnPointsUpdated(NewPoint);
	}
}

void APlatformerHUD::UpdateTime(float NewTime)
{
	if (InGameWidget)
	{
		InGameWidget->OnTimeUpdated(NewTime);
	}
}

void APlatformerHUD::ShowEndGame(float FinalTime, int32 FinalPoints)
{
	if (InGameWidget)
	{
		InGameWidget->RemoveFromParent();
	}

	if (GameOverWidget)
	{
		GameOverWidget->RemoveFromParent();
	}

	if (EndGameWidget)
	{
		EndGameWidget->AddToViewport();
		EndGameWidget->OnGameEnding(FinalPoints, FinalTime);
	}
}

void APlatformerHUD::ShowGameOver()
{
	if (InGameWidget)
	{
		InGameWidget->RemoveFromParent();
	}

	if (EndGameWidget)
	{
		EndGameWidget->RemoveFromParent();
	}

	if (GameOverWidget)
	{
		GameOverWidget->AddToViewport();
	}
}
