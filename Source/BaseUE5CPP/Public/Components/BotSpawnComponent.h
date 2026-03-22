// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BotSpawnComponent.generated.h"

class APawn;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BASEUE5CPP_API UBotSpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBotSpawnComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SpawnComponent")
	TSubclassOf<APawn> BotClass;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SpawnComponent", meta=(ClampMin = "0.0"))
	float SpawnRadius;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SpawnComponent", meta=(ClampMin = "0.1"))
	float SpawnInterval = 5.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SpawnComponent", meta =(ClampMin="1"))
	float MaxBotAlive = 3;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SpawnComponent")
	float SpawnZOffset = 0.0f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SpawnComponent")
	bool bDrawDebugRadius = true;
	
	
private:
	FTimerHandle SpawnTimerHandle;
	
	UPROPERTY()
	TArray<TObjectPtr<APawn>> SpawnedBots;
	
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
private:
	void TrySpawnBots();
	void CleanupInvalidBots();
	FVector GetRandomSpawnLocation() const;
	
};
