// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformCoopGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

#include <dbgeng.h>

UPuzzlePlatformCoopGameInstance::UPuzzlePlatformCoopGameInstance()
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBP(TEXT("/Game/Blueprints/UI/WBP_MainMenu"));

	MenuClass = MenuBP.Class;
}

void UPuzzlePlatformCoopGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Class Found : %s"), *MenuClass->GetName());
}

void UPuzzlePlatformCoopGameInstance::Host()
{
	UEngine* Engine = GetEngine();

	if(!ensure(Engine != nullptr)) return;
	
	Engine->AddOnScreenDebugMessage(0, 5, FColor::Cyan, TEXT("Host Function Called!"));

	UWorld* World = GetWorld();

	if(!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Maps/Tower?listen");
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

void UPuzzlePlatformCoopGameInstance::LoadMainMenu()
{
	UUserWidget* Menu = CreateWidget(this, MenuClass);
	if(!ensure(Menu != nullptr)) return;
	
	Menu->AddToViewport();

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if(!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly InputMode;

	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetWidgetToFocus(Menu->TakeWidget());
	
	PlayerController->SetInputMode(InputMode);
	PlayerController->SetShowMouseCursor(true);

}


