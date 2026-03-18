// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Base_InterractItem.h"


// Sets default values
ABase_InterractItem::ABase_InterractItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);
	
	
}

// Called when the game starts or when spawned
void ABase_InterractItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABase_InterractItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

