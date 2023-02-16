// Shooter, All Rights Reserved.


#include "UI/SettingOptionWidget.h"
#include "Settings/STUGameSetting.h"
#include "Components/TextBlock.h"

void USettingOptionWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void USettingOptionWidget::Init(USTUGameSetting* InSetting)
{
	Setting = MakeWeakObjectPtr(InSetting);
	check(Setting.IsValid());

	UpdateTexts();
}

void USettingOptionWidget::UpdateTexts()
{
	if (Setting.IsValid())
	{
		SettingDisplayName->SetText(FText::FromString(Setting->GetName()));
		SettingCurrentValue->SetText(FText::FromString(Setting->GetCurrentOption().Name));
	}
}
