// Shooter, All Rights Reserved.


#include "Player/STUPlayerController.h"
#include "Components/STURespawnComponent.h"

ASTUPlayerController::ASTUPlayerController()
{
	STURespawnComponent = CreateDefaultSubobject<USTURespawnComponent>("RespawnComponent");
}