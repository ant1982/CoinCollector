// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACoin::ACoin()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Set up Collision Sphere
    TriggerSphere = CreateDefaultSubobject<USphereComponent>(TEXT("TriggerSphere"));
    RootComponent = TriggerSphere;   
    TriggerSphere->SetupAttachment(RootComponent);
    TriggerSphere->SetCollisionProfileName("OverlapAll");

    // Set up the coin mesh component
    CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>("Coin Mesh");
    CoinMesh->SetupAttachment(GetRootComponent());
    CoinMesh->SetRelativeLocation(FVector(-10.f,0.f,0.f));
    CoinMesh->SetRelativeRotation(FRotator(-90.f,0.f,0.f));
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
    Super::BeginPlay();

    // Set up overlap events
    TriggerSphere->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnOverlapBegin);
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Handle overlap events with other actors
void ACoin::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    UE_LOG(LogTemp, Warning, TEXT("Overlapped With Pawn"));
    if (CollectSound)
    {
        // Play the coin collection sound effect
        UGameplayStatics::PlaySoundAtLocation(this, CollectSound,GetActorLocation());
    }
    // Destroy the coin actor
    Destroy();
}

