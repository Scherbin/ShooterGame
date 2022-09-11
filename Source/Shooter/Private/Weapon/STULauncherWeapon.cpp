// Shooter, All Rights Reserved.


#include "Weapon/STULauncherWeapon.h"
#include "Weapon/STUProjecttile.h"
#include"Kismet/GameplayStatics.h"

void ASTULauncherWeapon::StartFire()
{
	MakeShot();
}
void ASTULauncherWeapon::MakeShot()
{
	const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
	auto Projecttile = UGameplayStatics::BeginDeferredActorSpawnFromClass(GetWorld(), ProjecttileClass, SpawnTransform);

	UGameplayStatics::FinishSpawningActor(Projecttile, SpawnTransform);
}
