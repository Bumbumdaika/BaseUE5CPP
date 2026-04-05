// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TeleportComponent.h"


// Sets default values for this component's properties
UTeleportComponent::UTeleportComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	TeleportSpeed = 5.f;
	
	TeleportDistance = 100.f;
	// ...
}


// Called when the game starts
void UTeleportComponent::BeginPlay()
{
	Super::BeginPlay();

	GetOwner()->GetWorldTimerManager().SetTimer(TimerHandle, this, &UTeleportComponent::TeleportTimer,TeleportSpeed, true);
	// ...
	
}


// Called every frame
void UTeleportComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FVector UTeleportComponent::TeleportPoint(float Radius)
{
	FVector TeleportPoint = GetOwner()->GetActorLocation();
	FVector2D TeleportPoint2D = FMath::RandPointInCircle(Radius);
	TeleportPoint.X += TeleportPoint2D.X;
	TeleportPoint.Y += TeleportPoint2D.Y;
	return TeleportPoint;
}

void UTeleportComponent::TeleportTimer()
{
	FVector Offset = TeleportPoint(TeleportDistance);
	GetOwner()->SetActorLocation(Offset);
}


