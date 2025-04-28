// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/SpringAnimInstance.h"
#include "Characters/SpringCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void USpringAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	SpringCharacter = Cast<ASpringCharacter>(TryGetPawnOwner());

	if (SpringCharacter)
	{
		SpringCharacterMovement = SpringCharacter->GetCharacterMovement();
	}
}

void USpringAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (SpringCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(SpringCharacterMovement->Velocity);
		IsFalling = SpringCharacterMovement->IsFalling();
		CharacterState = SpringCharacter->GetCharacterState();
	}
}
