// Fill out your copyright notice in the Description page of Project Settings.


#include "KillComponent.h"

UKillComponent::UKillComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UKillComponent::BeginPlay()
{
	Super::BeginPlay();

	UStaticMeshComponent* Mesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();

	if (!Mesh)
	{
		UE_LOG(LogTemp, Warning,
			TEXT("KillComponent : no StaticMeshComponent find on %s"), *GetOwner()->GetName());
		return;
	}

	Mesh->OnComponentHit.AddDynamic(this, &UKillComponent::OnHit);

	Mesh->SetNotifyRigidBodyCollision(true);
}

void UKillComponent::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	APGJ1205_PlatformerCharacter* Character = Cast<APGJ1205_PlatformerCharacter>(OtherActor);

	if (!Character)
		return;

	Character->Die();
}


