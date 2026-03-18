// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemies/AIControllers/AIController_BaseEnemy.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"

const FName AAIController_BaseEnemy::TargetActorKeyName(TEXT("TargetActor"));

AAIController_BaseEnemy::AAIController_BaseEnemy()
{
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>("PerceptionComp");
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>("SightConfig");
	
	SightConfig->SightRadius = 1500.f;
	SightConfig->LoseSightRadius = 1500.f;
	SightConfig->SetMaxAge(5.f);
	
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	
	PerceptionComp->ConfigureSense(*SightConfig);
	PerceptionComp->SetDominantSense(UAISense_Sight::StaticClass());
	
	PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &AAIController_BaseEnemy::OnTargetPerceptionUpdated);
	
}

void AAIController_BaseEnemy::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}

void AAIController_BaseEnemy::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus AIStimulus)
{
	UBlackboardComponent* BlackboardComponent = GetBlackboardComponent();
	if (!Blackboard || !Actor)
	{
		return;
	}
	
	ACharacter* CharacterActor = Cast<ACharacter>(Actor);
	if (!CharacterActor)
	{
		return;
	}
	
	if (AIStimulus.WasSuccessfullySensed())
	{
		BlackboardComponent->SetValueAsObject(TEXT("TargetActor"), Actor);
		BlackboardComponent->SetValueAsBool(TEXT("CanSeeTarget"), true);
		BlackboardComponent->SetValueAsVector(TEXT("LastKnownLocation"), Actor->GetActorLocation());
		
	}
	else
	{
		BlackboardComponent->SetValueAsBool(TEXT("CanSeeTarget"), false);
		BlackboardComponent->SetValueAsVector(TEXT("LastKnownLocation"), Actor->GetActorLocation());
		
	}
	
}

void AAIController_BaseEnemy::SetTargetActor(AActor* Actor)
{
	if (UBlackboardComponent* BlackboardComponent = GetBlackboardComponent())
	{
		BlackboardComponent->SetValueAsObject(TargetActorKeyName, Actor);
		UE_LOG(LogTemp, Warning, TEXT("SetTargetActor: %s"), *Actor->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SetTargetActor Failed"));
	}
}

void AAIController_BaseEnemy::ClearTargetActor()
{
	 if (UBlackboardComponent* BlackboardComponent = GetBlackboardComponent())
	 {
		 BlackboardComponent->SetValueAsObject(TargetActorKeyName, nullptr);
	 }
}






