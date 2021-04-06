// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MenuInterface.h"
#include "MenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "InGameMenu.generated.h"

/**
 * 
 */
UCLASS()
class GDTV_PUZZLEPLATFORMS_API UInGameMenu : public UMenuWidget
{
	GENERATED_BODY()
protected:
	virtual bool Initialize() override;

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* ReturnToMainMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* CloseMenuButton;

	UFUNCTION()
	void CloseMenu();

	UFUNCTION()
	void ReturnToMainMenu();

	UFUNCTION()
	void QuitTheGame();
};
