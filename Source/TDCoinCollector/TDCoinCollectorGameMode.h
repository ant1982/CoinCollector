// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TDCoinCollectorGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreUpdatedSignature, int32, NewScore);

UCLASS(minimalapi)
class ATDCoinCollectorGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATDCoinCollectorGameMode();

	void AddScore(int32 CoinValue);

	UPROPERTY(BlueprintAssignable)
		FOnScoreUpdatedSignature OnScoreUpdatedDelegate;

protected:

	void NotifyScoreUpdated();

private:

	int32 CoinTotal;
};



