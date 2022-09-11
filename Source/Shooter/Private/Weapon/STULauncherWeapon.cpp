// Shooter, All Rights Reserved.


#include "Weapon/STULauncherWeapon.h"
#include "Weapon/STUProjecttile.h"

void ASTULauncherWeapon::StartFire()
{
	MakeShot();
}
void ASTULauncherWeapon::MakeShot()
{
	if (!GetWorld()) return;

	FVector TraceStart, TraceEnd;
	if (!GetTraceData(TraceStart, TraceEnd)) return;

	FHitResult HitResult;
	MakeHit(HitResult, TraceStart, TraceEnd);

	const FVector EndPoint = HitResult.bBlockingHit ? HitResult.ImpactPoint : TraceEnd;
	const FVector Direction = (EndPoint - GetMuzzleWorldLocation()).GetSafeNormal();

	const FTransform SpawnTransform(FRotator::ZeroRotator, GetMuzzleWorldLocation());
	ASTUProjecttile* Projecttile = GetWorld()->SpawnActorDeferred<ASTUProjecttile>(ProjecttileClass, SpawnTransform);
	if (Projecttile)
	{
		Projecttile->SetShotDirection(Direction);
		Projecttile->FinishSpawning(SpawnTransform);
	}
}
