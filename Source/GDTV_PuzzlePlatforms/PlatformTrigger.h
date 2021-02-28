// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "MovingPlatform.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "PlatformTrigger.generated.h"

UCLASS()
class GDTV_PUZZLEPLATFORMS_API APlatformTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformTrigger();

	// Called every frame
    virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* TriggerVolume;

	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	TArray<class AMovingPlatform*> PlatformsToTrigger;

	UPROPERTY(EditAnywhere)
	UStaticMesh* InactiveMesh;

	UPROPERTY(EditAnywhere)
	UStaticMesh* ActiveMesh;

	UPROPERTY(EditAnywhere)
	USoundBase* TriggeredSound;

	void SwapMesh(UStaticMesh* NewMesh);
};
