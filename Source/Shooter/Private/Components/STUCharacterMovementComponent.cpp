// Shooter, All Rights Reserved.


#include "Components/STUCharacterMovementComponent.h"
#include "Player/STUBase_Character.h"


float USTUCharacterMovementComponent::GetMaxSpeed() const
{
	const float MaxSpeed = Super::GetMaxSpeed();
	const ASTUBase_Character* Player = Cast<ASTUBase_Character>(GetPawnOwner());
	return Player && Player->IsRunning() ? MaxSpeed * RunModifier: MaxSpeed;
}