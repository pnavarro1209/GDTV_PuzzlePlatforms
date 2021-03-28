// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"
#include "Serialization/JsonTypes.h"

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if(!Success) return false;

	//Setup
	if(!ensure(HostButton != nullptr)) return false;
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	if(!ensure(JoinButton != nullptr)) return false;
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	if(!ensure(BackButton != nullptr)) return false;
	BackButton->OnClicked.AddDynamic(this, &UMainMenu::OpenMainMenu);

	if(!ensure(JoinServerButton != nullptr)) return false;
	JoinServerButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	return true;
}

void UMainMenu::SetMenuInterface(IMenuInterface* Interface)
{
	MenuInterface = Interface;
}

void UMainMenu::SetupMainMenu()
{
	this->AddToViewport();

	UWorld* World = GetWorld();
	if(!ensure(World != nullptr)) return;
	
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if(!ensure(PlayerController != nullptr)) return;

	FInputModeUIOnly InputMode;

	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputMode.SetWidgetToFocus(this->TakeWidget());
	
	PlayerController->SetInputMode(InputMode);
	PlayerController->bShowMouseCursor = true;
}

void UMainMenu::TearDown()
{
	this->RemoveFromViewport();

	UWorld* World = GetWorld();
	if(!ensure(World != nullptr)) return;
	
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if(!ensure(PlayerController != nullptr)) return;

	PlayerController->bShowMouseCursor = false;

	FInputModeGameOnly InputMode;
	PlayerController->SetInputMode(InputMode);
}

void UMainMenu::HostServer()
{
	if(MenuInterface != nullptr)
	{
		MenuInterface->Host();
	}
}

void UMainMenu::OpenJoinMenu()
{
	if(!ensure(SwitchMenu != nullptr)) return;
	if(!ensure(JoinMenu != nullptr)) return;
	SwitchMenu->SetActiveWidget(JoinMenu);
}

void UMainMenu::OpenMainMenu()
{
	if(!ensure(SwitchMenu != nullptr)) return;
	if(!ensure(MainMenu != nullptr)) return;
	SwitchMenu->SetActiveWidget(MainMenu);
}

void UMainMenu::JoinServer()
{
	if(MenuInterface != nullptr)
	{
		if(!ensure(UserTextInput != nullptr)) return;
		const FString& Address = UserTextInput->GetText().ToString();

		MenuInterface->Join(Address);
	}
}
