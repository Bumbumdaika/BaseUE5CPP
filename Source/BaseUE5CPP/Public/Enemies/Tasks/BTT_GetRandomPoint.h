#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h" // ВАЖНО
#include "BTT_GetRandomPoint.generated.h"

UCLASS()
class BASEUE5CPP_API UBTT_GetRandomPoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	UBTT_GetRandomPoint();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float SeachRadius = 1000.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FName PatrolPointKey = TEXT("PatrolPoint");
	
};