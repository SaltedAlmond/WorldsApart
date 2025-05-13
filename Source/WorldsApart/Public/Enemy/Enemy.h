// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "Interfaces/HitInterface.h"
#include "Characters/CharacterTypes.h"
#include "Enemy.generated.h"

class UHealthBarComponent;
class UPawnSensingComponent;

UCLASS()
class WORLDSAPART_API AEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AEnemy();

	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

private:
	UPROPERTY(VisibleAnywhere)
	UHealthBarComponent* HealthBarWidget;

	UPROPERTY(VisibleAnywhere)
	UPawnSensingComponent* PawnSensing;

	UPROPERTY()
	AActor* CombatTarget;

	UPROPERTY(EditAnywhere)
	double CombartRadius = 500.f;

	UPROPERTY(EditAnywhere)
	double PatrolRadius = 200.f;

	UPROPERTY(EditAnywhere)
	double AttackRadius = 150.f;

	/**
	* Navigation
	*/
	UPROPERTY()
	class AAIController* EnemyController;

	// Current patrol target
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	AActor* PatrolTarget;

	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TArray<AActor*> PatrolTargets;

	FTimerHandle PatrolTimer;

	void PatrolTimerFinished();

	UPROPERTY(EditAnywhere, Category = "AI Navigation")
	float WaitMin = 5.f;
	UPROPERTY(EditAnywhere, Category = "AI Navigation")
	float WaitMax = 10.f;

	const float ChaseSpeed = 300.f;

	EEnemyState EnemyState = EEnemyState::EES_Patrolling;

protected:
	virtual void BeginPlay() override;

	virtual void Die() override;

	bool InTargetRange(AActor* Target, double Radius);

	void MoveToTarget(AActor* Target);

	AActor* ChoosePatrolTarget();

	UFUNCTION()
	void PawnSeen(APawn* SeenPawn);

	UPROPERTY(BlueprintReadOnly)
	EDeathPose DeathPose = EDeathPose::EDP_Alive;

public:	
	virtual void Tick(float DeltaTime) override;

	void CheckPatrolTarget();

	void CheckCombatTarget();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
