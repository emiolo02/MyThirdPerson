// Fill out your copyright notice in the Description page of Project Settings.


#include "MyThirdPersonChar.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyThirdPersonChar::AMyThirdPersonChar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyThirdPersonChar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyThirdPersonChar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyThirdPersonChar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveRight", this, &AMyThirdPersonChar::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyThirdPersonChar::MoveForward);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

void AMyThirdPersonChar::MoveRight(float value)

{
	if (Controller == nullptr && value == 0.0f)
	{
		return;
	}

	const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
	const FVector Direction = UKismetMathLibrary::GetRightVector(YawRotation);

	AddMovementInput(Direction, value);
}

void AMyThirdPersonChar::MoveForward(float value)

{
	if (Controller == nullptr && value == 0.0f)
	{
		return;
	}

	const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
	const FVector Direction = UKismetMathLibrary::GetForwardVector(YawRotation);

	AddMovementInput(Direction, value);
}