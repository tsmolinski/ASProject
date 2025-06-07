// Fill out your copyright notice in the Description page of Project Settings.


#include "ASProjectUIManagerHUD.h"
#include "Kismet/GameplayStatics.h"
#include "../ASProjectBaseUI.h"
#include "../Tags/ASProjectBaseUITags.h"
#include "../Widgets/ASProjectActivatableWidget.h"

void AASProjectUIManagerHUD::BeginPlay()
{
	Super::BeginPlay();

	TObjectPtr<APlayerController> PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController)
	{
		if (UASProjectBaseUIWidgetClass)
		{
			UASProjectBaseUIWidget = CreateWidget<UASProjectBaseUI>(PlayerController, UASProjectBaseUIWidgetClass);

			UASProjectBaseUIWidget->AddToViewport();
		}
	}

	ShowPlayerHUDWidget();
}

void AASProjectUIManagerHUD::ShowPlayerHUDWidget()
{
	if (UASProjectBaseUIWidget)
	{
		if (PlayerHUDWidgetClass)
		{
			PlayerHUDWidget = UASProjectBaseUIWidget->PushWidgetToLayer<UASProjectActivatableWidget>(TAG_UI_Layer_GameStack, PlayerHUDWidgetClass);
		}
	}
}

void AASProjectUIManagerHUD::ShowInGameMenuWidget()
{
	if (UASProjectBaseUIWidget)
	{
		if (InGameMenuWidgetClass)
		{
			InGameMenuWidget = UASProjectBaseUIWidget->PushWidgetToLayer<UASProjectActivatableWidget>(TAG_UI_Layer_GameMenuStack, InGameMenuWidgetClass);
		}
	}
}

void AASProjectUIManagerHUD::HideInGameMenuWidget()
{
	if (UASProjectBaseUIWidget)
	{
		if (InGameMenuWidget)
		{
			UASProjectBaseUIWidget->FindAndRemoveWidgetFromLayer(InGameMenuWidget);
		}
	}
}
