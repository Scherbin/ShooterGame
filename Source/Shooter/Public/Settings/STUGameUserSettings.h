// Shooter, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "STUGameUserSettings.generated.h"

class USTUGameSetting;

UCLASS()
class SHOOTER_API USTUGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()
	
public:
	USTUGameUserSettings();
	static USTUGameUserSettings* Get();

	const TArray< USTUGameSetting*>& GetVideoSettings() const;

private:
	TArray< USTUGameSetting*> VideoSettings;
};
