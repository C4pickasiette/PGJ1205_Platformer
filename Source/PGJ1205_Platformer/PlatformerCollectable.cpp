// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformerCollectable.h"

// Sets default values
APlatformerCollectable::APlatformerCollectable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	Mesh->OnComponentBeginOverlap.AddDynamic(this, &APlatformerCollectable::OnOverlapBegin);
	RootComponent = Mesh;
}

void APlatformerCollectable::OnCollected(AActor* OtherActor)
{
}

void APlatformerCollectable::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnCollected(OtherActor);
	SetActorEnableCollision(false); 
	SetActorHiddenInGame(true);   
}


