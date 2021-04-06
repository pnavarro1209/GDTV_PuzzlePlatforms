// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UI/MenuInterface.h"
#include "PuzzlePlatformCoopGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GDTV_PUZZLEPLATFORMS_API UPuzzlePlatformCoopGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UPuzzlePlatformCoopGameInstance();
	
	void Init() override;

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);

	UFUNCTION(BlueprintCallable)
	void LoadMainMenu();

	UFUNCTION(BlueprintCallable)
	void LoadInGameMenu();

	UFUNCTION()
	virtual void ReturnToLobby() override;

	virtual void QuitGame() override;

private:
	TSubclassOf<class UUserWidget> MenuClass;

	class UMenuWidget* Menu;

	TSubclassOf<class UUserWidget> InGameMenuClass;

	class UMenuWidget* InGameMenu;
};
