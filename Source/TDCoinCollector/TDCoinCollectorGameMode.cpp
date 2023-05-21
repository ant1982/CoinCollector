// Copyright Epic Games, Inc. All Rights Reserved.

#include "TDCoinCollectorGameMode.h"
#include "TDCoinCollectorPlayerController.h"
#include "TDCoinCollectorCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATDCoinCollectorGameMode::ATDCoinCollectorGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ATDCoinCollectorPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}

void ATDCoinCollectorGameMode::AddScore(int32 CoinValue)
{
	CoinTotal += CoinValue;
	UE_LOG(LogTemp, Warning, TEXT("Score is: %d "), CoinTotal);
}
