// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class GDTV_PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

	void AddActiveTrigger();

	void RemoveActiveTrigger();

private:
	UPROPERTY(EditAnywhere)
	float MovementSpeed = 10;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

	FVector StartingLocation;
	FVector GlobalTarget;

	UPROPERTY(EditAnywhere)
	int CountActiveTriggers = 1;
};
