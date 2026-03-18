// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AISense_Sight.h"
#include "AIController_BaseEnemy.generated.h"
/**
 * 
 */
class UAIPerceptionComponent;
class UAISenseConfig_Sight;
class UBehaviorTree;
class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS()
class BASEUE5CPP_API AAIController_BaseEnemy : public AAIController
{
	GENERATED_BODY()
	
public:
	AAIController_BaseEnemy();
	static const FName TargetActorKeyName;
	
protected:
	
	
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	TObjectPtr<UBehaviorTree> BehaviorTree;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	TObjectPtr<UAIPerceptionComponent> PerceptionComp;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	TObjectPtr<UAISenseConfig_Sight> SightConfig;

	virtual void OnPossess(APawn* InPawn) override;	
	
	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus AIStimulus);
	
	void SetTargetActor(AActor* Actor);
	void ClearTargetActor();
};
