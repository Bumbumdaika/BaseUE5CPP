// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/BotSpawnComponent.h"

#include"Engine/World.h"
#include "GameFramework/Pawn.h"
#include "TimerManager.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UBotSpawnComponent::UBotSpawnComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBotSpawnComponent::BeginPlay()
{
	Super::BeginPlay();

	if (bDrawDebugRadius && GetOwner())
	{
		DrawDebugSphere(GetWorld(), GetOwner()->GetActorLocation(), SpawnRadius, 24,FColor::Green, true, 10.0f);
	}
	
	if (!GetOwner())
	{
		UE_LOG(LogTemp, Warning, TEXT("GetOwner() is null"));
	}
	
	if (!BotClass)
	{
		UE_LOG(LogTemp, Warning, TEXT("BotClass is null"));
	}
	
	TrySpawnBots();
	
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &UBotSpawnComponent::TrySpawnBots, SpawnInterval, true);
}


// Called every frame
void UBotSpawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



void UBotSpawnComponent::CleanupInvalidBots()
{
	SpawnedBots.RemoveAll([](const TObjectPtr<APawn>& Bot){return !IsValid(Bot);});
}

FVector UBotSpawnComponent::GetRandomSpawnLocation() const
{
	if (!GetOwner())
	{
		return FVector::ZeroVector;	
	}
	
	const FVector OwnerLocation = GetOwner()->GetActorLocation();
	
	const FVector2D RandomPoint2D = FMath::RandPointInCircle(SpawnRadius);
	
	FVector SpawnLocation;
	SpawnLocation.X = OwnerLocation.X + RandomPoint2D.X;
	SpawnLocation.Y = OwnerLocation.Y + RandomPoint2D.Y;
	SpawnLocation.Z = OwnerLocation.Z + SpawnZOffset;
	
	return SpawnLocation;
}



void UBotSpawnComponent::TrySpawnBots()
{
	if (!GetWorld() || !GetOwner() || !BotClass)
	{
		return;
	}

	
	CleanupInvalidBots();
	
	const FVector SpawnLocation = GetRandomSpawnLocation();
	const FRotator SpawnRotation = FRotator::ZeroRotator;
	
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = GetOwner();
	SpawnParams.Instigator = Cast<APawn>(GetOwner());
	SpawnParams.SpawnCollisionHandlingOverride =  ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	APawn* SpawnedBot = GetWorld()->SpawnActor<APawn>(BotClass, SpawnLocation, SpawnRotation, SpawnParams);
	if (!SpawnedBot)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawned BPT is null"));
		return;
	}
	
	SpawnedBots.Add(SpawnedBot);
	
	UE_LOG(LogTemp, Warning, TEXT("BotSpawnerActorComponent: Spawned bot %s"), *SpawnedBot->GetName());
}