// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "WorldsApart/DebugMacros.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
}

float AItem::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	//float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	float DeltaX = TransformedSin();
	float DeltaY = TransformedCos();

	AddActorWorldOffset(FVector(DeltaX, DeltaY, 0.f));
	AddActorWorldRotation(FRotator(0.f, DeltaTime + 5.f, 0.f));

	//DRAW_SPHERE_SingleFrame(GetActorLocation());
	//DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);

}

