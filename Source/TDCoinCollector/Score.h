// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Score.generated.h"

/**
 * 
 */
UCLASS()
class TDCOINCOLLECTOR_API UScore : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

protected:

	virtual bool Initialize();

	UFUNCTION()
		void UpdateScoreText(int32 Score);

private:

	UPROPERTY(meta = (BindWidget))
		class UTextBlock* CurrentScoreText;
	
};
