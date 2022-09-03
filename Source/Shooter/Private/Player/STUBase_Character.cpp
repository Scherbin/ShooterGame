// Shooter, All Rights Reserved.


#include "Player/STUBase_Character.h"
#include"Camera/CameraComponent.h"

// Sets default values
ASTUBase_Character::ASTUBase_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ASTUBase_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASTUBase_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASTUBase_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

