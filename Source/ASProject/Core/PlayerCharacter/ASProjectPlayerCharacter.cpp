// Fill out your copyright notice in the Description page of Project Settings.


#include "ASProjectPlayerCharacter.h"
#include "EnhancedInputComponent.h"

// Sets default values
AASProjectPlayerCharacter::AASProjectPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int AASProjectPlayerCharacter::GetCurrentEnergy() const
{
	return CurrentEnergy;
}

int AASProjectPlayerCharacter::GetMaxEnergy() const
{
	return MaxEnergy;
}

void AASProjectPlayerCharacter::ChangeEnergy(int Value)
{
	CurrentEnergy += Value;

	OnEnergyChangedDelegate.Broadcast(Value);
}

// Called when the game starts or when spawned
void AASProjectPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	MaxEnergy = 99;
	
	CurrentEnergy = 0;
	
	EnergyChunk = 33;
}

void AASProjectPlayerCharacter::DPadLeftClicked()
{
	ChangeEnergy(EnergyChunk);
	UE_LOG(LogTemp, Warning, TEXT("DPadLeftClicked: %d"), EnergyChunk);
}

void AASProjectPlayerCharacter::DPadUpClicked()
{
	ChangeEnergy(EnergyChunk);
	UE_LOG(LogTemp, Warning, TEXT("DPadLeftClicked: %d"), EnergyChunk);
}

void AASProjectPlayerCharacter::DPadRightClicked()
{
	ChangeEnergy(EnergyChunk);
	UE_LOG(LogTemp, Warning, TEXT("DPadLeftClicked: %d"), EnergyChunk);
}

// Called every frame
void AASProjectPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AASProjectPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(DPadLeftAction, ETriggerEvent::Started, this, &ACharacter::Jump);

		EnhancedInputComponent->BindAction(DPadUpAction, ETriggerEvent::Started, this, &ACharacter::Jump);

		EnhancedInputComponent->BindAction(DPadRightAction, ETriggerEvent::Started, this, &ACharacter::Jump);
	}

}

