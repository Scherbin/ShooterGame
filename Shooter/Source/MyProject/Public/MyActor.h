// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywere,Category="Weapons")
	int32 WeaponsNum = 4;

	UPROPERTY(EditDefaultsOnly,Category="Stat")
	int32 KillsNum = 7;

	UPROPERTY(EditInstanceOnly,Category="Health")
	float Health = 34.00090;

	UPROPERTY(EditAnywere,Category="Health")
	bool IsDead = false;

	UPROPERTY(VisibleAnywere,Category="Weapons")
	bool HasWeapon = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	void PrintTypes();
	void PrintStringTypes();



};
