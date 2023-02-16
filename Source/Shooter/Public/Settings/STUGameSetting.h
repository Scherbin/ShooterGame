// Shooter, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "STUGameSetting.generated.h"

USTRUCT()
struct FSettingOption
{
	GENERATED_BODY()

		FString Name;

	    int32 Value;
};

UCLASS()
class USTUGameSetting : public UObject
{
	GENERATED_BODY()

public:

	void SetName(const FString& InName);
	void SetOptions(const TArray<FSettingOption>& InOptions);

	FSettingOption GetCurrentOption() const;
	FString GetName() const;

private:
	FString Name;

	TArray<FSettingOption> Options;
};