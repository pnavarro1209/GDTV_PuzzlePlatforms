// Fill out your copyright notice in the Description page of Project Settings.


#include "CoopEscapeCrystal.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ACoopEscapeCrystal::ACoopEscapeCrystal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	if(!ensure(TriggerVolume != nullptr)) return;
	SetRootComponent(TriggerVolume);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button Default Mesh"));
	Mesh->SetupAttachment(TriggerVolume);

}

void ACoopEscapeCrystal::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if(HasAuthority())
	{
		UWorld* World = GetWorld();

		if(!ensure(World != nullptr)) return;

		World->ServerTravel("/Game/Maps/Escaped");
	}
}

// Called when the game starts or when spawned
void ACoopEscapeCrystal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoopEscapeCrystal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

