#include "Enemies/Tasks/BTT_GetRandomPoint.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"
#include "GameFramework/Pawn.h"

UBTT_GetRandomPoint::UBTT_GetRandomPoint()
{
	NodeName = TEXT("Get Random Point");
}

EBTNodeResult::Type UBTT_GetRandomPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AIController = OwnerComp.GetAIOwner();
	if (!AIController)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController is NULL"));
		return EBTNodeResult::Failed;
	}
	
	APawn* ControllerPawn = AIController->GetPawn();
	if (!ControllerPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("ControllerPawn is NULL"));
		return EBTNodeResult::Failed;
	}
	
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp)
	{
		UE_LOG(LogTemp, Error, TEXT("BlackboardComp is NULL"));
		return EBTNodeResult::Failed;
	}
	
	FNavLocation RandomLocation;
	const FVector Origin = ControllerPawn->GetActorLocation();
	
	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	if (!NavSystem)
	{
		UE_LOG(LogTemp, Error, TEXT("NavSystem is NULL"));
		return EBTNodeResult::Failed;
	}
	
	const bool bFoundPoint = NavSystem -> GetRandomReachablePointInRadius (Origin, SeachRadius, RandomLocation);
	
	BlackboardComp->SetValueAsVector(PatrolPointKey, RandomLocation.Location);
	
	UE_LOG(LogTemp, Warning, TEXT("BTT_GetRandomPoint: Patrol point set to %s"), *RandomLocation.Location.ToString());

	return EBTNodeResult::Succeeded;
	
}