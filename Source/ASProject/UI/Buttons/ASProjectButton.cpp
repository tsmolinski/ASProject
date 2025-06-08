// Fill out your copyright notice in the Description page of Project Settings.


#include "ASProjectButton.h"
#include "CommonTextBlock.h"
#include "Internationalization/Text.h"

void UASProjectButton::SetButtonText(FText InText)
{
	DisplayedText->SetText(InText);
}

void UASProjectButton::NativePreConstruct()
{
	Super::NativePreConstruct();
	
	if (DisplayedText)
	{
		DisplayedText->SetText(ButtonText);
	}
}

void UASProjectButton::NativeOnCurrentTextStyleChanged()
{
	Super::NativeOnCurrentTextStyleChanged();
	
	DisplayedText->SetStyle(GetCurrentTextStyleClass());
}
