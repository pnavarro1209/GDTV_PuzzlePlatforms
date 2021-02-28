// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformTrigger.h"

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlatformTrigger::APlatformTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	if(!ensure(TriggerVolume != nullptr)) return;
	SetRootComponent(TriggerVolume);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button Default Mesh"));
	Mesh->SetupAttachment(TriggerVolume);
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void APlatformTrigger::SwapMesh(UStaticMesh* NewMesh)
{
	Mesh->SetStaticMesh(NewMesh);
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
	
	SwapMesh(ActiveMesh);

	UGameplayStatics::PlaySoundAtLocation(this, TriggeredSound, GetActorLocation(), GetActorRotation());
}

void APlatformTrigger::NotifyActorEndOverlap(AActor* OtherActor)
{
	if(!ensure(!PlatformsToTrigger.Num() == 0)) return;
	for (AMovingPlatform* Platform : PlatformsToTrigger)
	{
		Platform->RemoveActiveTrigger();
	}
	
	SwapMesh(InactiveMesh);
}



