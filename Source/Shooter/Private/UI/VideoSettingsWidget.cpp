// Shooter, All Rights Reserved.


#include "UI/VideoSettingsWidget.h"
#include "Settings/STUGameUserSettings.h"
#include "Components/VerticalBox.h"
#include "Components/Button.h"
#include "UI/SettingOptionWidget.h"

DEFINE_LOG_CATEGORY_STATIC(LogVideoSettingsWidget, All, All);

void UVideoSettingsWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	auto* UserSettings = USTUGameUserSettings::Get();
	if (!UserSettings)
	{
		UE_LOG(LogVideoSettingsWidget, Error, TEXT("USTUGameUserSettings is nullptr"));
		return;
	}

	UserSettings->LoadSettings();
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
	check(RunBenchmarkButton);
	RunBenchmarkButton->OnClicked.AddDynamic(this, &ThisClass::OnBenchmark);

	UserSettings->OnVideoSettingUpdate.AddUObject(this, &ThisClass::OnVideoSettingsUpdate);
}

void UVideoSettingsWidget::OnBenchmark()
{
	if (auto* UserSettings = USTUGameUserSettings::Get())
	{
		UserSettings->RunBenchmark();
	}
}

void UVideoSettingsWidget::OnVideoSettingsUpdate()
{
	if (!VideoSettingsContainer)return;
	for (auto* Widget : VideoSettingsContainer->GetAllChildren())
	{
		if (auto* SettingOptionWidget = Cast<USettingOptionWidget>(Widget))
		{
			SettingOptionWidget->UpdateTexts();
		}
	}
}
