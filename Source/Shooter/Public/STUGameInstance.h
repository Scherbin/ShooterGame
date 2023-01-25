// Shooter, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "STUCoreTypes.h"
#include "STUGameInstance.generated.h"

class USoundClass;

UCLASS()
class SHOOTER_API USTUGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	FLevelData GetStartUpLevel() const { return  StartUpLevel; }
	void SetStartUpLevel(const FLevelData& Data) { StartUpLevel = Data; }

	TArray<FLevelData> GetLevelsData() const { return LevelsData; }

	FName GetMenuLevelName() const { return  MenuLevelName; }

	void ToggleVolume();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Game", meta = (ToolTip = "Level names must be unique!"))
	TArray<FLevelData> LevelsData;

	UPROPERTY(EditDefaultsOnly, Category = "Game")
	FName MenuLevelName = NAME_None;

	UPROPERTY(EditDefaultsOnly, Category = "Sound")
	USoundClass* MasterSoundClass;

private:
	FLevelData StartUpLevel;
};
