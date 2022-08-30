// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include"Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry,All,All)
// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	// PrintTypes();
	//PrintStringTypes();

	
} 

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::PrintTypes()
{
	UE_LOG(LogBaseGeometry,Warning,TEXT("Actor name %s"),*GetName())
	UE_LOG(LogBaseGeometry, Warning, TEXT("Weapons num: %d,Kills num: %i"), WeaponsNum, KillsNum);
	UE_LOG(LogBaseGeometry, Warning, TEXT("Health: %f"), Health);
	UE_LOG(LogBaseGeometry, Warning, TEXT("Is Dead %d,"), IsDead);
	UE_LOG(LogBaseGeometry, Warning, TEXT("HasWeapon %d,"), static_cast<int>(HasWeapon));

}
void AMyActor::PrintStringTypes()
{
	FString Name = "John Conor";

	UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name);

	
	FString WeaponsNumStr = "Weapons Num " + FString::FromInt(WeaponsNum);
	FString HealthStr = " Health " + FString::SanitizeFloat(Health);
	FString IsDeadStr = " Is dead " + FString(IsDead ? "true" : "false");

	FString Stat = FString::Printf(TEXT("\n== All Stat==\n %s\n %s\n %s"), *WeaponsNumStr, *HealthStr, *IsDeadStr);

	UE_LOG(LogBaseGeometry, Warning, TEXT("%s"), *Stat);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Name);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, Stat, true, FVector2D(1.5f, 1.5f));
}

