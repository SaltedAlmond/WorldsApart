// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Collectibles.generated.h"

/**
 * 
 */
UCLASS()
class WORLDSAPART_API ACollectibles : public AItem
{
	GENERATED_BODY()

protected:

	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	
	UPROPERTY(EditAnywhere, Category = "Gold Properties");
	int32 Gold;
};
