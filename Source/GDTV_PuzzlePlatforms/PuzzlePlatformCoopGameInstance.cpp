// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformCoopGameInstance.h"

#include <dbgeng.h>

UPuzzlePlatformCoopGameInstance::UPuzzlePlatformCoopGameInstance()
{

}

void UPuzzlePlatformCoopGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Log from Init"));
}

void UPuzzlePlatformCoopGameInstance::Host()
{
	UEngine* Engine = GetEngine();

	if(!ensure(Engine != nullptr)) return;
	
	Engine->AddOnScreenDebugMessage(0, 5, FColor::Cyan, TEXT("Host Function Called!"));

	UWorld* World = GetWorld();

	if(!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatformCoopGameInstance::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();

	if(!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining: %s"), *Address));
	
	UWorld* World = GetWorld();

	if(!ensure(World != nullptr)) return;

	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if(!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
