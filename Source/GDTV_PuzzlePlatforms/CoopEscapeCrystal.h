// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "CoopEscapeCrystal.generated.h"

UCLASS()
class GDTV_PUZZLEPLATFORMS_API ACoopEscapeCrystal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoopEscapeCrystal();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* TriggerVolume;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;
};
