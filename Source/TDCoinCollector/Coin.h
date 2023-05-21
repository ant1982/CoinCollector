// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundBase.h"
#include "Coin.generated.h"

UCLASS()
class TDCOINCOLLECTOR_API ACoin : public AActor
{
	GENERATED_BODY()
	
public:
    // Sets default values for this actor's properties
    ACoin();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Handle overlap events with other actors
    UFUNCTION()
        void OnOverlapBegin(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


protected:

    // Collision Sphere for overlap events
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
        class USphereComponent* TriggerSphere;

    // Sound effect played when the coin is collected
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sound Cue")
        class USoundBase* CollectSound;

private:

    // Coin mesh component
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
        class UStaticMeshComponent* CoinMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin Score", meta = (AllowPrivateAccess = "true"))
        int32 CoinValue = 1;

};
