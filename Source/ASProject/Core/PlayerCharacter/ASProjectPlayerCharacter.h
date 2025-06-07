// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ASProjectPlayerCharacter.generated.h"

class UInputAction;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnergyChangedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnergySlotChangedSignature, UInputAction*, InputAction);

UCLASS()
class ASPROJECT_API AASProjectPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AASProjectPlayerCharacter();

	UFUNCTION(BlueprintCallable)
	float GetCurrentEnergy() const;

	UFUNCTION(BlueprintCallable)
	float GetMaxEnergy() const;

	//UFUNCTION(BlueprintCallable)
	void ChangeEnergy(float Value);

	UPROPERTY(BlueprintAssignable)
	FOnEnergyChangedSignature OnEnergyChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnEnergySlotChangedSignature FOnEnergySlotChangedDelegate;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void DPadLeftClicked();
	
	void DPadUpClicked();
	
	void DPadRightClicked();

	void InGameMenuActionClicked();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere)
	float CurrentEnergy;

	UPROPERTY(VisibleAnywhere)
	float MaxEnergy;

	UPROPERTY(VisibleAnywhere)
	float EnergyChunk;

	bool LeftIndicatorFilled = false;
	bool UpIndicatorFilled = false;
	bool RightIndicatorFilled = false;

	bool IsInGameMenuShown = false;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> DPadLeftAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> DPadUpAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> DPadRightAction;
	
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> InGameMenuAction;
};
