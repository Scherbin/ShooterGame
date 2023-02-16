// Shooter, All Rights Reserved.


#include "Settings/STUGameUserSettings.h"
#include "Settings/STUGameSetting.h"

USTUGameUserSettings::USTUGameUserSettings()
{
	const TArray<FSettingOption> VFXOptions = {{"Low", 0}, {"Medium", 1}, {"Hight", 2}, {"Epic", 3}};

	{
		auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
		Setting->SetName("Anti-Aliasing");
		Setting->SetOptions(VFXOptions);
		VideoSettings.Add(Setting);
	}
	
	{
	    auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
	    Setting->SetName("Textures");
	    Setting->SetOptions(VFXOptions);
	    VideoSettings.Add(Setting);
	}

	{
		auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
		Setting->SetName("Global Illumination");
		Setting->SetOptions(VFXOptions);
		VideoSettings.Add(Setting);
	}

	{
		auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
		Setting->SetName("Shadows");
		Setting->SetOptions(VFXOptions);
		VideoSettings.Add(Setting);
	}

	{
		auto* Setting = NewObject<USTUGameSetting>();
		check(Setting);
		Setting->SetName("Post Processing");
		Setting->SetOptions(VFXOptions);
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
