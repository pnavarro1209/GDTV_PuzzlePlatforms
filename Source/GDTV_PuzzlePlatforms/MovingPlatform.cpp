// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
#include "Math/Vector.h"

#include <Actor.h>

#include "Algo/Count.h"

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

	StartingLocation = GetActorLocation();
	GlobalTarget = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(CountActiveTriggers >0)
	{
		if(HasAuthority())
        	{
        		FVector CurrentLocation = GetActorLocation();
        		float CurrentLength = (CurrentLocation - StartingLocation).Size();
        		float MaxLength = (GlobalTarget - StartingLocation).Size();
        		
        		if(CurrentLength >= MaxLength)
        		{
        			FVector Swap = StartingLocation;
        			StartingLocation = GlobalTarget;
        			GlobalTarget = Swap;
        		}
        		
        		FVector Direction = (GlobalTarget - CurrentLocation).GetSafeNormal();
        		CurrentLocation += MovementSpeed * DeltaSeconds * Direction;
        		
        		SetActorLocation(CurrentLocation);
        	}
	}
	
}

void AMovingPlatform::AddActiveTrigger()
{
	CountActiveTriggers++;
}

void AMovingPlatform::RemoveActiveTrigger()
{
	CountActiveTriggers--;
}


