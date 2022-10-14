// Shooter, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "STUFireService.generated.h"

UCLASS()
class SHOOTER_API USTUFireService : public UBTService
{
	GENERATED_BODY()
	
public:
	USTUFireService();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FBlackboardKeySelector EnemyActorKey;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSecond) override;
};
