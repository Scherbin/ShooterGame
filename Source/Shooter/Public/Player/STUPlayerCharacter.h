// Shooter, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/STUBase_Character.h"
#include "STUPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USphereComponent;

UCLASS()
class SHOOTER_API ASTUPlayerCharacter : public ASTUBase_Character
{
	GENERATED_BODY()
	

public:
	ASTUPlayerCharacter(const FObjectInitializer& ObjInit);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USphereComponent* CameraCollisionComponent;

	virtual void OnDeath() override;
	virtual void BeginPlay() override;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual bool IsRunning() const override;

private:
	bool WantsToRun = false;
	bool IsMovingForvard = false;

	void MoveForvard(float Amount);
	void MoveRight(float Amount);

	void OnStartRunning();
	void OnStopRunning();

	UFUNCTION()
	void OnCameraCollisionBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnCameraCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void ChekCameraOverlap();
};