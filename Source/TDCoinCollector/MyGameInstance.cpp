// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Blueprint/UserWidget.h"

UMyGameInstance::UMyGameInstance(const FObjectInitializer& Objectinitializer)
{
	// Test code for static constructor helpers and blueprint user widgets
	static ConstructorHelpers::FClassFinder<UUserWidget> GameScoreBPClass(TEXT("/Game/Widgets/WBP_Score"));
	if (!ensure(GameScoreBPClass.Class != nullptr)) return;

	GameHUDClass = GameScoreBPClass.Class;
}

