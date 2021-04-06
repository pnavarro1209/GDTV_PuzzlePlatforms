// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"

#include "Components/Button.h"
#include "GenericPlatform/GenericWindowDefinition.h"

bool UInGameMenu::Initialize()
{
	Super::Initialize();

	if(!ensure(QuitButton != nullptr)) return false;
	QuitButton->OnClicked.AddDynamic(this, &UInGameMenu::QuitTheGame);
	
	if(!ensure(ReturnToMainMenuButton != nullptr)) return false;
	ReturnToMainMenuButton->OnClicked.AddDynamic(this, &UInGameMenu::ReturnToMainMenu);
	
	if(!ensure(CloseMenuButton != nullptr)) return false;
	CloseMenuButton->OnClicked.AddDynamic(this, &UInGameMenu::CloseMenu);

	return true;
}

void UInGameMenu::CloseMenu()
{
	TearDown();
}

void UInGameMenu::ReturnToMainMenu()
{
	MenuInterface->ReturnToLobby();
	TearDown();
}

void UInGameMenu::QuitTheGame()
{
	MenuInterface->QuitGame();
}
