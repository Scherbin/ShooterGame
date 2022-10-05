// Shooter, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Pickups/STUBasePickup.h"
#include "STUAmmoPickup.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTER_API ASTUAmmoPickup : public ASTUBasePickup
{
	GENERATED_BODY()
	
private:
	virtual bool GivePickupTo(APawn* PlayerPawn) override;
};
