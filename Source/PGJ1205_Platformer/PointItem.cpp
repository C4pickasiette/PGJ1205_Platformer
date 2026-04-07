// Fill out your copyright notice in the Description page of Project Settings.


#include "PointItem.h"

void APointItem::OnCollected(AActor* OtherActor)
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (!PC) return;

	APlatformerPlayerState* PS = PC->GetPlayerState<APlatformerPlayerState>();
	if (!PS) return;

	PS->AddScore(PointValue);
}