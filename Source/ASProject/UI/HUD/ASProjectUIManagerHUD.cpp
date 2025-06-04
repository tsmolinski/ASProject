// Fill out your copyright notice in the Description page of Project Settings.


#include "ASProjectUIManagerHUD.h"
#include "Kismet/GameplayStatics.h"
#include "../ASProjectBaseUI.h"

void AASProjectUIManagerHUD::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController)
	{
		if (UASProjectBaseUIWidgetClass)
		{
			UASProjectBaseUIWidget = CreateWidget<UASProjectBaseUI>(PlayerController, UASProjectBaseUIWidgetClass);

			UASProjectBaseUIWidget->AddToViewport();
		}
	}
}
