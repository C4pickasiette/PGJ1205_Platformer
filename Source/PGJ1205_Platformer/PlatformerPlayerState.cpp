// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerPlayerState.h"

void APlatformerPlayerState::AddScore(int32 Amount)
{
	PlayerScore += Amount;


	APGJ1205_PlatformerGameMode* GM = Cast<APGJ1205_PlatformerGameMode>(GetWorld()->GetAuthGameMode());
	if (GM)
		GM->NotifyPointsChanged(PlayerScore);
}