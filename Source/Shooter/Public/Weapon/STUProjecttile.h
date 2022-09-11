// Shooter, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUProjecttile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class SHOOTER_API ASTUProjecttile : public AActor
{
	GENERATED_BODY()
	
public:	
	ASTUProjecttile();

	void SetShotDirection(const FVector& Direction) { ShotDirection = Direction; }

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = "Weapon")
		UProjectileMovementComponent* MovementComponent;

		virtual void BeginPlay() override;
private:
	FVector ShotDirection;
};
