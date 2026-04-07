// Fill out your copyright notice in the Description page of Project Settings.


#include "LinearMovementComponent.h"

void ULinearMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	if (AActor* Owner = GetOwner())
	{
		StartLocation = Owner->GetActorLocation();
	}
}

void ULinearMovementComponent::UpdateMovement(float DeltaTime)
{
	ElapsedTime += DeltaTime;

	float Offset = FMath::Sin(ElapsedTime * Speed) * Amplitude;
	FVector NewLocation = StartLocation + Axis.GetSafeNormal() * Offset;

	GetOwner()->SetActorLocation(NewLocation);
}
