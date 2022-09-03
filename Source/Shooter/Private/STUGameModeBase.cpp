// Shooter.All Rights Reserved.


#include "STUGameModeBase.h"
#include "Player/STUBase_Character.h"
#include "Player/STUPlayerController.h"

ASTUGameModeBase::ASTUGameModeBase()
{
	DefaultPawnClass = ASTUBase_Character::StaticClass();
	PlayerControllerClass = ASTUPlayerController::StaticClass();
}
