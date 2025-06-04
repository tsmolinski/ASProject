// Fill out your copyright notice in the Description page of Project Settings.


#include "ASProjectActivatableWidget.h"

TOptional<FUIInputConfig> UASProjectActivatableWidget::GetDesiredInputConfig() const
{
	switch (InputConfig)
	{
	case EASProjectWidgetInputMode::All:
		return FUIInputConfig(ECommonInputMode::All, GameMouseCaptureMode);
		
	case EASProjectWidgetInputMode::Game:
		return FUIInputConfig(ECommonInputMode::Game, GameMouseCaptureMode);
		
	case EASProjectWidgetInputMode::Menu:
		return FUIInputConfig(ECommonInputMode::Menu, EMouseCaptureMode::NoCapture);
		
	case EASProjectWidgetInputMode::Default:
	default:
		return TOptional<FUIInputConfig>();
	}
}
