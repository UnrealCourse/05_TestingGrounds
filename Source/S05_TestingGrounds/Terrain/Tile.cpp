// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "Tile.h"
#include "DrawDebugHelpers.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATile::PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn, float ClearRadius) {
	int NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);
	for (size_t i = 0; i < NumberToSpawn; i++)
	{
		FVector SpawnPoint; 
		bool found = FindEmptySpace(SpawnPoint, ClearRadius);
		if (found) {
			PlaceActor(ToSpawn, SpawnPoint);
		}
	}
}

bool ATile::FindEmptySpace(FVector& OutLocation, float ClearRadius)
{
	FVector Min(0, -2000, 0);
	FVector Max(4000, 2000, 0);
	FBox Bounds(Min, Max);
	const int MAX_ATTEMPTS = 100;
	for (size_t i = 0; i < MAX_ATTEMPTS; i++)
	{
		OutLocation = FMath::RandPointInBox(Bounds);
		if (!SphereCast(OutLocation, ClearRadius)) {
			return true;
		}
	}

	return false;
}

const ECollisionChannel ECC_Spawn = ECollisionChannel::ECC_GameTraceChannel2;

bool ATile::SphereCast(FVector Location, float Radius)
{
	FHitResult Hit;
	FVector GlobalLocation = GetActorTransform().TransformPosition(Location); // NOTE: Not .TransformVector()
	bool hasHit = GetWorld()->SweepSingleByChannel(
		Hit,
		GlobalLocation,
		GlobalLocation,
		FQuat::Identity, //NOTE: Not FQuat()
		ECC_Spawn,
		FCollisionShape::MakeSphere(Radius)
	);
	FColor ResultColor = hasHit ? FColor::Red : FColor::Green;
	DrawDebugCapsule(GetWorld(), GlobalLocation, 0, Radius, FQuat::Identity, ResultColor, true, 100);
	return hasHit;
}

void ATile::PlaceActor(TSubclassOf<AActor> &ToSpawn, const FVector &SpawnPoint)
{
	AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
	Spawned->SetActorRelativeLocation(SpawnPoint);
	Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

