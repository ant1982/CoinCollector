// Fill out your copyright notice in the Description page of Project Settings.


#include "Score.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"
#include "TDCoinCollectorGameMode.h"

void UScore::NativeConstruct()
{
	Super::NativeConstruct();

	ATDCoinCollectorGameMode* GameMode = Cast<ATDCoinCollectorGameMode>(UGameplayStatics::GetGameMode(this));

	if (GameMode)
	{
		GameMode->OnScoreUpdatedDelegate.AddUniqueDynamic(this, &ThisClass::UpdateScoreText);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Game mode not found"));
	}
}

bool UScore::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(CurrentScoreText != nullptr)) return false;
	
	return true;
}

void UScore::UpdateScoreText(int32 Score)
{
	CurrentScoreText->SetText(FText::FromString(FString::FromInt(Score)));
}
