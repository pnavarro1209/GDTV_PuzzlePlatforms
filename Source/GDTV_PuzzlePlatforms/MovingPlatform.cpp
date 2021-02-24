// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

#include <Actor.h>

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	bReplicates = true;
	SetReplicatingMovement(true);

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(HasAuthority())
	{
		FVector ActorLocation = GetActorLocation();
        
        ActorLocation += FVector(movementSpeed * DeltaSeconds, 0, 0);

		SetActorLocation(ActorLocation);
	}
}


