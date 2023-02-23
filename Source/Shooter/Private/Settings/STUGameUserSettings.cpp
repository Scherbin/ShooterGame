// Shooter, All Rights Reserved.


#include "Settings/STUGameUserSettings.h"
#include "Settings/STUGameSetting.h"

#define LOCTEXT_NAMESPACE "GameUserSettings"

USTUGameUserSettings::USTUGameUserSettings()
{
	const TArray<FSettingOption> VFXOptions = //
	{
	    {LOCTEXT("VFXQualityLow_Loc", "Low"), 0},           //
		{LOCTEXT("VFXQualityMedium_Loc", "Medium"), 1},    //
		{LOCTEXT("VFXQualityHight_Loc", "Hight"), 2},     //
		{LOCTEXT("VFXQualityEpic_Loc", "Epic"), 3},      //
	};

	{
		auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
		Setting->SetName(LOCTEXT("AntiAliasing_Loc", "Anti-Aliasing"));
		Setting->SetOptions(VFXOptions);
		Setting->AddGetter([&]() { return GetAntiAliasingQuality(); });
		Setting->AddSetter([&](int32 Level) { SetAntiAliasingQuality(Level); ApplySettings(false); });
		VideoSettings.Add(Setting);
	}
	
	{
	    auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
	    Setting->SetName(LOCTEXT("Textures_Loc", "Textures"));
	    Setting->SetOptions(VFXOptions);
		Setting->AddGetter([&]() { return GetTextureQuality(); });
		Setting->AddSetter([&](int32 Level) { SetTextureQuality(Level); ApplySettings(false); });
	    VideoSettings.Add(Setting);
	}

	{
		auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
		Setting->SetName(LOCTEXT("ViewDistance_Loc", "ViewDistance"));
		Setting->SetOptions(VFXOptions);
		Setting->AddGetter([&]() { return GetViewDistanceQuality(); });
		Setting->AddSetter([&](int32 Level) { SetViewDistanceQuality(Level); ApplySettings(false); });
		VideoSettings.Add(Setting);
	}

	{
		auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
		Setting->SetName(LOCTEXT("Shadows_Loc", "Shadows"));
		Setting->SetOptions(VFXOptions);
		Setting->AddGetter([&]() {return GetShadowQuality(); });
		Setting->AddSetter([&](int32 Level) { SetShadowQuality(Level); ApplySettings(false); });
		VideoSettings.Add(Setting);
	}

	{
		auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
		Setting->SetName(LOCTEXT("PostProcessing_Loc", "PostProcessing"));
		Setting->SetOptions(VFXOptions);
		Setting->AddGetter([&]() {return GetPostProcessingQuality(); });
		Setting->AddSetter([&](int32 Level) { SetPostProcessingQuality(Level); ApplySettings(false); });
		VideoSettings.Add(Setting);
	}
	
	{
		auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
		Setting->SetName(LOCTEXT("Foliage_Loc", "Foliage"));
		Setting->SetOptions(VFXOptions);
		Setting->AddGetter([&]() {return  GetFoliageQuality(); });
		Setting->AddSetter([&](int32 Level) { SetFoliageQuality(Level); ApplySettings(false); });
		VideoSettings.Add(Setting);
	}

	{
		auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
		Setting->SetName(LOCTEXT("Shading_Loc", "Shading"));
		Setting->SetOptions(VFXOptions);
		Setting->AddGetter([&]() {return GetShadingQuality(); });
		Setting->AddSetter([&](int32 Level) { SetShadingQuality(Level); ApplySettings(false); });
		VideoSettings.Add(Setting);
	}

	{
		auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
		Setting->SetName(LOCTEXT("Effects_Loc", "Effects"));
		Setting->SetOptions(VFXOptions);
		Setting->AddGetter([&]() {return GetVisualEffectQuality(); });
		Setting->AddSetter([&](int32 Level) { SetVisualEffectQuality(Level); ApplySettings(false); });
		VideoSettings.Add(Setting);
	}

}

USTUGameUserSettings* USTUGameUserSettings::Get()
{
	return GEngine ? Cast<USTUGameUserSettings>(GEngine->GetGameUserSettings()) : nullptr;
}

const TArray<USTUGameSetting*>& USTUGameUserSettings::GetVideoSettings() const
{
	return VideoSettings;
}

void USTUGameUserSettings::RunBenchmark()
{
	RunHardwareBenchmark();
	ApplySettings(false);
	OnVideoSettingUpdate.Broadcast();
}

#undef LOCTEXT_NAMESPACE 