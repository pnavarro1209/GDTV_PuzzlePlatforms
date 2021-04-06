// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformCoopGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"
#include "UI/MainMenu.h"

#include <dbgeng.h>

#include "UI/InGameMenu.h"

UPuzzlePlatformCoopGameInstance::UPuzzlePlatformCoopGameInstance()
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBP(TEXT("/Game/Blueprints/UI/WBP_MainMenu"));

	MenuClass = MenuBP.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> InGameMenuBP(TEXT("/Game/Blueprints/UI/WBP_GameMenu"));

	InGameMenuClass = InGameMenuBP.Class;
}

void UPuzzlePlatformCoopGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Class Found : %s"), *MenuClass->GetName());
}

void UPuzzlePlatformCoopGameInstance::Host()
{
	if(Menu != nullptr)
	{
		Menu->TearDown();
	}
	
	UEngine* Engine = GetEngine();

	if(!ensure(Engine != nullptr)) return;
	
	Engine->AddOnScreenDebugMessage(0, 5, FColor::Cyan, TEXT("Host Function Called!"));

	UWorld* World = GetWorld();

	if(!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/Maps/Tower?listen");
}

void UPuzzlePlatformCoopGameInstance::Join(const FString& Address)
{
	if(Menu != nullptr)
	{
		Menu->TearDown();
	}
	
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
	Menu = CreateWidget<UMenuWidget>(this, MenuClass);
	if(!ensure(Menu != nullptr)) return;
	Menu->Setup();
	Menu->SetMenuInterface(this);
}

void UPuzzlePlatformCoopGameInstance::LoadInGameMenu()
{
	InGameMenu = CreateWidget<UMenuWidget>(this, InGameMenuClass);
	if(!ensure(InGameMenu != nullptr)) return;
	InGameMenu->Setup();
	InGameMenu->SetMenuInterface(this);
}

void UPuzzlePlatformCoopGameInstance::ReturnToLobby()
{
	UWorld* World = GetWorld();

	if(!ensure(World != nullptr)) return;

	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if(!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel("/Game/Maps/Lobby", ETravelType::TRAVEL_Absolute);
}

void UPuzzlePlatformCoopGameInstance::QuitGame()
{
	UWorld* World = GetWorld();

	if(!ensure(World != nullptr)) return;

	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if(!ensure(PlayerController != nullptr)) return;

	PlayerController->ConsoleCommand("quit");
}


