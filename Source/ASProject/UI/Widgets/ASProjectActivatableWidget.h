// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "ASProjectActivatableWidget.generated.h"

struct FUIInputConfig;

/**
 * 
 */

UENUM(BlueprintType)
enum class EASProjectWidgetInputMode : uint8
{
	All,
	Game,
	Menu,
	Default
};

UCLASS()
class ASPROJECT_API UASProjectActivatableWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

public:
	virtual TOptional<FUIInputConfig> GetDesiredInputConfig() const override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = Input)
	EASProjectWidgetInputMode InputConfig = EASProjectWidgetInputMode::Default;

	UPROPERTY(EditDefaultsOnly, Category = Input)
	EMouseCaptureMode GameMouseCaptureMode = EMouseCaptureMode::CapturePermanently;
};
