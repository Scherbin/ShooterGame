// Shooter, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SettingOptionWidget.generated.h"

class UTextBlock;
class USTUGameSetting;

UCLASS()
class SHOOTER_API USettingOptionWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* SettingDisplayName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* SettingCurrentValue;

	virtual void NativeOnInitialized() override;

private:
	TWeakObjectPtr<USTUGameSetting> Setting;

	void Init(USTUGameSetting* InSetting);
	void UpdateTexts();

	friend class UVideoSettingsWidget;
};
