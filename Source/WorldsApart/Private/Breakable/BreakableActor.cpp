#include "Breakable/BreakableActor.h"
//#include "GeometryCollection/GeometryCollectionComponent.h"
#include "Items/Collectibles.h"
#include "Components/CapsuleComponent.h"

ABreakableActor::ABreakableActor()
{
	PrimaryActorTick.bCanEverTick = false;

	//GeometryCollection = CreateDefaultSubobject<UGeometryCollectionComponent>(TEXT("GeometryCollection"));
	//SetRootComponent(GeometryCollection);
	//GeometryCollection->SetGenerateOverlapEvents(true);
	//GeometryCollection->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	//GeometryCollection->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

	BreakableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	BreakableMesh->SetGenerateOverlapEvents(true);

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetupAttachment(GetRootComponent());
	Capsule->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	Capsule->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
}

void ABreakableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABreakableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABreakableActor::GetHit_Implementation(const FVector& ImpactPoint)
{
	if (bBroken) return;

	bBroken = true;

	UWorld* World = GetWorld();
	if (World &&  CollectibleClasses.Num() > 0)
	{
		FVector Location = GetActorLocation();
		Location.Z += 75.f;

		int32 Selection = FMath::RandRange(0, CollectibleClasses.Num() * 2);

		if (Selection <= CollectibleClasses.Num() - 1)
		{
			World->SpawnActor<ACollectibles>(CollectibleClasses[Selection], Location, GetActorRotation());
		}
	}
	this->Destroy();
}

