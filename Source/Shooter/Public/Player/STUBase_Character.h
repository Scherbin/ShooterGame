

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STUBase_Character.generated.h"

class USTUHealthComponent;
class USTUHealthComponent;
class USTUWeaponComponent;
class USoundCue;

UCLASS()
class SHOOTER_API ASTUBase_Character : public ACharacter
{
	GENERATED_BODY()

public:
	ASTUBase_Character(const FObjectInitializer& ObjInit);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USTUHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USTUWeaponComponent* WeaponComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* DeathAnimMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float LifeSpanOnDeath = 5.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	FVector2D LandedDamageVelocity = FVector2D(900.0f,1200.0f);

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	FVector2D LandedDamage = FVector2D(10.0f, 100.0f);

	UPROPERTY(EditDefaultsOnly, Category = "Material")
	FName MaterialColorName = "Paint Color";

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Sound")
	USoundCue* DeathSound;

	UFUNCTION()
	virtual void OnDeath();

	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnHealthChanged(float Health, float HealthDelta);


public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	virtual bool IsRunning() const;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	float GetMovementDirection() const;

	void SetPlayerColor(const FLinearColor& Color);

private:
	UFUNCTION()
	void OnGroundLanded(const FHitResult& Hit);

};
