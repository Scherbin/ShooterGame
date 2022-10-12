// Shooter, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/STUBase_Character.h"
#include "STUAICharacter.generated.h"

class UBehaviorTree;

UCLASS()
class SHOOTER_API ASTUAICharacter : public ASTUBase_Character
{
	GENERATED_BODY()


public:
	ASTUAICharacter(const FObjectInitializer& ObjInit);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTreeAsset;
};
