// Fill out your copyright notice in the Description page of Project Settings.


#include "ASProjectPlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "Kismet/GameplayStatics.h"
#include "../../UI/HUD/ASProjectUIManagerHUD.h"

// Sets default values
AASProjectPlayerCharacter::AASProjectPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

float AASProjectPlayerCharacter::GetCurrentEnergy() const
{
	return CurrentEnergy;
}

float AASProjectPlayerCharacter::GetMaxEnergy() const
{
	return MaxEnergy;
}

void AASProjectPlayerCharacter::ChangeEnergy(float Value)
{
	CurrentEnergy += Value;

	OnEnergyChangedDelegate.Broadcast();
}

// Called when the game starts or when spawned
void AASProjectPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	MaxEnergy = 100.f;
	
	CurrentEnergy = 0.f;
	
	EnergyChunk = 33.33f;
}

void AASProjectPlayerCharacter::DPadLeftClicked()
{
	if (!LeftIndicatorFilled)
	{
		ChangeEnergy(EnergyChunk);
	}
	else
	{
		ChangeEnergy(-1 * EnergyChunk);
	}
	LeftIndicatorFilled = !LeftIndicatorFilled;
	
	FOnEnergySlotChangedDelegate.Broadcast(DPadLeftAction);
}

void AASProjectPlayerCharacter::DPadUpClicked()
{
	if (!UpIndicatorFilled)
	{
		ChangeEnergy(EnergyChunk);
	}
	else
	{
		ChangeEnergy(-1 * EnergyChunk);
	}
	UpIndicatorFilled = !UpIndicatorFilled;
	
	FOnEnergySlotChangedDelegate.Broadcast(DPadUpAction);
}

void AASProjectPlayerCharacter::DPadRightClicked()
{
	if (!RightIndicatorFilled)
	{
		ChangeEnergy(EnergyChunk);
	}
	else
	{
		ChangeEnergy(-1 * EnergyChunk);
	}
	RightIndicatorFilled = !RightIndicatorFilled;
	
	FOnEnergySlotChangedDelegate.Broadcast(DPadRightAction);
}

void AASProjectPlayerCharacter::InGameMenuActionClicked()
{
	TObjectPtr<APlayerController> PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController)
	{
		TObjectPtr<AASProjectUIManagerHUD> PlayerHUD = Cast<AASProjectUIManagerHUD>(PlayerController->GetHUD());

		if (PlayerHUD)
		{
			PlayerHUD->ShowInGameMenuWidget();
		}
	}
}

// Called every frame
void AASProjectPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AASProjectPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(DPadLeftAction, ETriggerEvent::Started, this, &AASProjectPlayerCharacter::DPadLeftClicked);

		EnhancedInputComponent->BindAction(DPadUpAction, ETriggerEvent::Started, this, &AASProjectPlayerCharacter::DPadUpClicked);

		EnhancedInputComponent->BindAction(DPadRightAction, ETriggerEvent::Started, this, &AASProjectPlayerCharacter::DPadRightClicked);
		
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(InGameMenuAction, ETriggerEvent::Started, this, &AASProjectPlayerCharacter::InGameMenuActionClicked);
	}

}

