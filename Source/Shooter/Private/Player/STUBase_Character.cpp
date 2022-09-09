// Shooter, All Rights Reserved.


#include "Player/STUBase_Character.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/STUCharacterMovementComponent.h"
#include "Components/STUHealthComponent.h"
#include "Components/TextRenderComponent.h"

// Sets default values
ASTUBase_Character::ASTUBase_Character(const FObjectInitializer& ObjInit)
	:Super(ObjInit.SetDefaultSubobjectClass<USTUCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	HealthComponent = CreateDefaultSubobject<USTUHealthComponent>("HealthComponent");

	HealthTextComponent = CreateDefaultSubobject<UTextRenderComponent>("HealthTextComponent");
	HealthTextComponent->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ASTUBase_Character::BeginPlay()
{
	Super::BeginPlay();
	
	check(HealthComponent);
	check(HealthTextComponent);
}

// Called every frame
void ASTUBase_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const auto Health = HealthComponent->GetHealth();
	HealthTextComponent->SetText(FText::FromString(FString::Printf(TEXT("%.0f"), Health)));
}


// Called to bind functionality to input
void ASTUBase_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForvard", this, &ASTUBase_Character::MoveForvard);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASTUBase_Character::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ASTUBase_Character::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("TurnAround", this, &ASTUBase_Character::AddControllerYawInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed,this, &ASTUBase_Character::Jump);
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ASTUBase_Character::OnStartRunning);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &ASTUBase_Character::OnStopRunning);
}




void ASTUBase_Character::MoveForvard(float Amount)
{
	IsMovingForvard = Amount > 0.0f;
	if (Amount == 0.0f) return;
	AddMovementInput(GetActorForwardVector(),Amount);
}

void ASTUBase_Character::MoveRight(float Amount)
{
	if (Amount == 0.0f) return;
	AddMovementInput(GetActorRightVector(), Amount); 
}

void ASTUBase_Character::OnStartRunning()
{
	WantsToRun = true;
}

void ASTUBase_Character::OnStopRunning()
{
	WantsToRun = false;
}

bool ASTUBase_Character::IsRunning() const
{
	return WantsToRun && IsMovingForvard && !GetVelocity().IsZero();
}

float ASTUBase_Character::GetMovementDirection() const
{
	if (GetVelocity().IsZero()) return 0.0f;
	const auto VelocityNormal = GetVelocity().GetSafeNormal();
	const auto AngleBetween = FMath::Acos(FVector::DotProduct(GetActorForwardVector(), VelocityNormal));
	const auto CrossProduct = FVector::CrossProduct(GetActorForwardVector(), VelocityNormal);
	const auto Degrees = FMath::RadiansToDegrees(AngleBetween);
	return CrossProduct.IsZero() ? Degrees : Degrees* FMath::Sign(CrossProduct.Z);
		
}



