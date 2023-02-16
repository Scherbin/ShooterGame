// Shooter, All Rights Reserved.


#include "UI/VideoSettingsWidget.h"
#include "Settings/STUGameUserSettings.h"
#include "Components/VerticalBox.h"
#include "UI/SettingOptionWidget.h"

DEFINE_LOG_CATEGORY_STATIC(LogVideoSettingsWidget, All, All);

void UVideoSettingsWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	const auto* UserSettings = USTUGameUserSettings::Get();
	if (!UserSettings)
	{
		UE_LOG(LogVideoSettingsWidget, Error, TEXT("USTUGameUserSettings is nullptr"));
		return;
	}

	const auto VideoSettings = UserSettings->GetVideoSettings();
	check(VideoSettingsContainer);
	VideoSettingsContainer->ClearChildren();

	for (auto* Setting : VideoSettings)
	{
		const auto SettingWidget = CreateWidget<USettingOptionWidget>(this, SettingOptionWidgetClass);
		check(SettingWidget);
		SettingWidget->Init(Setting);
		VideoSettingsContainer->AddChild(SettingWidget);
	}
}
