// Fill out your copyright notice in the Description page of Project Settings.


#include "ASProjectBaseUI.h"

UCommonActivatableWidgetContainerBase* UASProjectBaseUI::GetLayerWidget(FGameplayTag LayerTag)
{
	return Layers.FindRef(LayerTag);
}

void UASProjectBaseUI::RegisterLayer(FGameplayTag LayerTag, UCommonActivatableWidgetContainerBase* Widget)
{
	Layers.Add(LayerTag, Widget);

	for (auto& layer : Layers)
	{
		UE_LOG(LogTemp, Log, TEXT("Tag: %s"), *layer.Key.ToString());
	}
}
