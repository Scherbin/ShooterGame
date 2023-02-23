// Shooter, All Rights Reserved.


#include "Settings/STUGameSetting.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTUGameSetting, All, All);

void USTUGameSetting::SetOptions(const TArray<FSettingOption>& InOptions)
{
    Options = InOptions;
}

FSettingOption USTUGameSetting::GetCurrentOption() const
{
    const int32 CurrentValue = GetCurrentValue();
    const auto Option = Options.FindByPredicate([&](const FSettingOption& Opt) {return CurrentValue == Opt.Value; });
    if (!Option)
    {
        UE_LOG(LogSTUGameSetting, Error, TEXT("Option doesn't exist"));
        return FSettingOption{};
    }
    return *Option;
}

FText USTUGameSetting::GetName() const
{
    return Name;
}
void USTUGameSetting::AddGetter(TFunction<int32()> Func)
{
    Getter = Func;
}
void USTUGameSetting::AddSetter(TFunction<void(int32)> Func)
{
    Setter = Func;
}
void USTUGameSetting::ApplyNextOption()
{
    const int32 CurrentIndex = GetCurrentIndex();
    if (CurrentIndex == INDEX_NONE) return;

    const int32 NextIndex = (CurrentIndex + 1) % Options.Num();
    SetCurrentValue(Options[NextIndex].Value);
}
void USTUGameSetting::ApplyPrevOption()
{
    const int32 CurrentIndex = GetCurrentIndex();
    if (CurrentIndex == INDEX_NONE) return;

    const int32 PrevIndex = CurrentIndex == 0 ? Options.Num() - 1 : CurrentIndex - 1;
    SetCurrentValue(Options[PrevIndex].Value);
}
int32 USTUGameSetting::GetCurrentValue() const
{
    if (!Getter)
    {
        UE_LOG(LogSTUGameSetting, Error, TEXT("Getter func is not set for %s"),*Name.ToString());
        return INDEX_NONE;
    }
    return Getter();
}
void USTUGameSetting::SetCurrentValue(int32 Value)
{
    if (!Setter)
    {
        UE_LOG(LogSTUGameSetting, Error, TEXT("Setter func is not set for %s"), *Name.ToString());
        return;
    }
    Setter(Value);
}
int32 USTUGameSetting::GetCurrentIndex() const
{
    const int32 CurrentValue = GetCurrentValue();
    return Options.IndexOfByPredicate([&](const auto& Opt) {return CurrentValue == Opt.Value; });
}
void USTUGameSetting::SetName(const FText& InName)
{
    Name = InName;
}

