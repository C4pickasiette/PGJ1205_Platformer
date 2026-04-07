// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformerCollectable.generated.h"

UCLASS(abstract)
class PGJ1205_PLATFORMER_API APlatformerCollectable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformerCollectable();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Collectable")
	TObjectPtr<UStaticMeshComponent> Mesh;

	virtual void OnCollected(AActor* OtherActor);

private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
