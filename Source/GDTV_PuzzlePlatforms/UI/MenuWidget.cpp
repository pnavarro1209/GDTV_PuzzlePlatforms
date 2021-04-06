// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

void UMenuWidget::Setup()
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

void UMenuWidget::TearDown()
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


void UMenuWidget::SetMenuInterface(IMenuInterface* Interface)
{
	MenuInterface = Interface;
}