// Shooter, All Rights Reserved.


#include "Settings/STUGameSetting.h"

void USTUGameSetting::SetOptions(const TArray<FSettingOption>& InOptions)
{
    Options = InOptions;
}

FSettingOption USTUGameSetting::GetCurrentOption() const
{
    return Options[0];
}

FString USTUGameSetting::GetName() const
{
    return Name;
}
void USTUGameSetting::SetName(const FString& InName)
{
    Name = InName;
}