// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Collectibles.h"
#include "Characters/SpringCharacter.h"

void ACollectibles::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASpringCharacter* SpringCharacter = Cast<ASpringCharacter>(OtherActor);
	if (SpringCharacter)
	{
		Destroy();
	}
}
