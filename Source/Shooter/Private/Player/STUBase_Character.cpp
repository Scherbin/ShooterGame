// Shooter, All Rights Reserved.


#include "Player/STUBase_Character.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ASTUBase_Character::ASTUBase_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
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

	PlayerInputComponent->BindAxis("MoveForvard", this, &ASTUBase_Character::MoveForvard);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASTUBase_Character::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ASTUBase_Character::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnAround", this, &ASTUBase_Character::AddControllerYawInput);
}

void ASTUBase_Character::MoveForvard(float Amount)
{
	AddMovementInput(GetActorForwardVector(),Amount);
}

void ASTUBase_Character::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}





