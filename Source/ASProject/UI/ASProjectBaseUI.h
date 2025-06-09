// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "GameplayTagContainer.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "ASProjectBaseUI.generated.h"

class UCommonActivatableWidgetContainerBase;

UCLASS()
class ASPROJECT_API UASProjectBaseUI : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	template <typename ActivatableWidgetT = UCommonActivatableWidget>
	ActivatableWidgetT* PushWidgetToLayer(FGameplayTag LayerName, UClass* ActivatableWidgetClass)
	{
		if (UCommonActivatableWidgetContainerBase* Layer = GetLayerWidget(LayerName))
		{
			return Layer->AddWidget<ActivatableWidgetT>(ActivatableWidgetClass);
		}

		return nullptr;
	}

	UCommonActivatableWidgetContainerBase* GetLayerWidget(FGameplayTag LayerTag);

	void FindAndRemoveWidgetFromLayer(UCommonActivatableWidget* ActivatableWidget);

protected:
	UFUNCTION(BlueprintCallable)
	void RegisterLayer(UPARAM(meta = (Categories = "UI.Layer")) FGameplayTag LayerTag, UCommonActivatableWidgetContainerBase* Widget);

private:
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UCommonActivatableWidgetContainerBase>> Layers;
	
};
