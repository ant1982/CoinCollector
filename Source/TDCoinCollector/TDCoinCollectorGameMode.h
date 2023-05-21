// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TDCoinCollectorGameMode.generated.h"

UCLASS(minimalapi)
class ATDCoinCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATDCoinCollectorGameMode();

	void AddScore(int32 CoinValue);

private:

	int32 CoinTotal;
};



