// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ASProjectUIManagerHUD.generated.h"

class UASProjectBaseUI;
class UASProjectActivatableWidget;

/**
 * This is a UI manager class. 
 */

UCLASS()
class ASPROJECT_API AASProjectUIManagerHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void ShowInGameMenuWidget();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI Base") 
	TSubclassOf<UASProjectBaseUI> UASProjectBaseUIWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UASProjectActivatableWidget> InGameMenuWidgetClass;

private:
	TObjectPtr<UASProjectBaseUI> UASProjectBaseUIWidget;

	TObjectPtr<UASProjectActivatableWidget> InGameMenuWidget;
};
