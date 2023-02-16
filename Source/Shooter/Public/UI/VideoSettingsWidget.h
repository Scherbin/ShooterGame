// Shooter, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VideoSettingsWidget.generated.h"

class UVerticalBox;
class USettingOptionWidget;

UCLASS()
class SHOOTER_API UVideoSettingsWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* VideoSettingsContainer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<USettingOptionWidget> SettingOptionWidgetClass;

	virtual void NativeOnInitialized() override;
};
