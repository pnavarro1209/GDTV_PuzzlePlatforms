// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatformCoopGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GDTV_PUZZLEPLATFORMS_API UPuzzlePlatformCoopGameInstance : public UGameInstance
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

	TSubclassOf<class UUserWidget> MenuClass;
};
