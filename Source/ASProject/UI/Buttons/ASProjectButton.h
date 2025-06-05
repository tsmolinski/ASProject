// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "ASProjectButton.generated.h"

class UCommonTextBlock;
class FText;

/**
 * 
 */
UCLASS()
class ASPROJECT_API UASProjectButton : public UCommonButtonBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ButtonText;

	UFUNCTION(BlueprintCallable)
	void SetButtonText(FText InText);

protected:
	virtual void NativePreConstruct() override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UCommonTextBlock> DisplayedText;
	
};
