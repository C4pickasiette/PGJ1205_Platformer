// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpItem.h"

void APowerUpItem::OnCollected(AActor* OtherActor)
{
	APGJ1205_PlatformerCharacter* Character = Cast<APGJ1205_PlatformerCharacter>(OtherActor);

	if (!Character)
		return;

	Character->ApplyPowerUp(Duration, SpeedMultiplier, JumpMultiplier);
}
