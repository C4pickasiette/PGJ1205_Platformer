// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerZone.h"

void ATimerZone::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ATimerZone::OnOverlapBegin);
}

void ATimerZone::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (!OtherActor)
		return;

	APGJ1205_PlatformerCharacter* Character = Cast<APGJ1205_PlatformerCharacter>(OtherActor);
	if (!Character)
		return;

	APGJ1205_PlatformerGameMode* GM = Cast<APGJ1205_PlatformerGameMode>(GetWorld()->GetAuthGameMode());
	if (!GM)
		return;

	switch (ZoneType)
	{
		case TimeZoneType::Start:
			GM->StartTimer();
			break;

		case TimeZoneType::End:
			GM->StopTimer();
			break;
	}
}

