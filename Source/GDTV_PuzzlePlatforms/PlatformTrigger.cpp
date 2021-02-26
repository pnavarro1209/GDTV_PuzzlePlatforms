// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformTrigger.h"

#include "Components/BoxComponent.h"

// Sets default values
APlatformTrigger::APlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	if(!ensure(TriggerVolume != nullptr)) return;
	RootComponent = TriggerVolume;
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlatformTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlatformTrigger::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if(!ensure(!PlatformsToTrigger.Num() == 0)) return;
	for (AMovingPlatform* Platform : PlatformsToTrigger)
	{
		Platform->AddActiveTrigger();
	}
}

void APlatformTrigger::NotifyActorEndOverlap(AActor* OtherActor)
{
	if(!ensure(!PlatformsToTrigger.Num() == 0)) return;
	for (AMovingPlatform* Platform : PlatformsToTrigger)
	{
		Platform->RemoveActiveTrigger();
	}
}



