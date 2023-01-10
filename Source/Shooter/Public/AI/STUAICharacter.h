// Shooter, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/STUBase_Character.h"
#include "STUAICharacter.generated.h"

class UBehaviorTree;
class UWidgetComponent;

UCLASS()
class SHOOTER_API ASTUAICharacter : public ASTUBase_Character
{
	GENERATED_BODY()


public:
	ASTUAICharacter(const FObjectInitializer& ObjInit);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* BehaviorTreeAsset;

	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UWidgetComponent* HealthWidgetComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	float HealthVisibilityDistance = 1000.0f;


	virtual void BeginPlay() override;
	virtual void OnDeath() override;
	void OnHealthChanged(float Health, float HealthDelta) override;

private:
	void UpdateHealthWidgetVisibility();

};
