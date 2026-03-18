#include "Enemies/Tasks/BTT_GetRandomPoint.h"
#include "AIController.h"

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
	
	return EBTNodeResult::Succeeded;
}