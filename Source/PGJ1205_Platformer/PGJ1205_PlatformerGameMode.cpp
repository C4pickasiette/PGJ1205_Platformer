// Copyright Epic Games, Inc. All Rights Reserved.

#include "PGJ1205_PlatformerGameMode.h"
#include "PGJ1205_PlatformerCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "PlatformerPlayerState.h"

APGJ1205_PlatformerGameMode::APGJ1205_PlatformerGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PrimaryActorTick.bCanEverTick = true;
}

void APGJ1205_PlatformerGameMode::OnPlayerDied()
{
	UE_LOG(LogTemp, Log, TEXT("Player died"));

	OnPlayerDiedDelegate.Broadcast();
	GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &APGJ1205_PlatformerGameMode::RestartLevel, 2.0f, false);
}

void APGJ1205_PlatformerGameMode::StartTimer()
{
	if (bTimer)
		return;

	ElapsedTime = 0.0f;
	bTimer = true;
}

void APGJ1205_PlatformerGameMode::StopTimer()
{
	if (!bTimer)
		return;

	bTimer = false;

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (!PC) return;

	APlatformerPlayerState* PS = PC->GetPlayerState<APlatformerPlayerState>();
	if (!PS) return;

	OnLevelFinished.Broadcast(ElapsedTime, PS->PlayerScore);

	FTimerHandle RestartTimerHandle;
	GetWorldTimerManager().SetTimer(RestartTimerHandle, this, &APGJ1205_PlatformerGameMode::RestartLevel, 5.0f, false);
}

float APGJ1205_PlatformerGameMode::GetElapsedTime() const
{
	return ElapsedTime;
}

void APGJ1205_PlatformerGameMode::NotifyPointsChanged(int32 NewPoints)
{
	OnPointsChanged.Broadcast(NewPoints);
}

void APGJ1205_PlatformerGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bTimer)
		return;

	ElapsedTime += DeltaTime;
	UE_LOG(LogTemp, Log, TEXT("Time : %f"), ElapsedTime);
	OnTimerUpdated.Broadcast(ElapsedTime);
}

void APGJ1205_PlatformerGameMode::RestartLevel()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()));
}