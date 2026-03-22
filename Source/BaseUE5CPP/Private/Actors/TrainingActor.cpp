// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/TrainingActor.h"


// Sets default values
ATrainingActor::ATrainingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	
}

// Called when the game starts or when spawned
void ATrainingActor::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ATrainingActor::MoveLocation, 1.f, true);
	
	
}

// Called every frame
void ATrainingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


FVector ATrainingActor::Offset2D(float Radius)
{
	FVector CurrentLocation = GetActorLocation();
	FVector2D RandomLocation2D = FMath::RandPointInCircle(Radius);
	CurrentLocation.X += RandomLocation2D.X;
	CurrentLocation.Y += RandomLocation2D.Y;
	return CurrentLocation;
}

void ATrainingActor::MoveLocation()
{
	FVector OffsetLocation = Offset2D(500.f);
	SetActorLocation(OffsetLocation);
	
}






