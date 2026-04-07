// Fill out your copyright notice in the Description page of Project Settings.


#include "RotationMovementComponent.h"

void URotationMovementComponent::UpdateMovement(float DeltaTime)
{
	FRotator DeltaRotation = RotationRate * DeltaTime;
	GetOwner()->AddActorLocalRotation(DeltaRotation);
}
