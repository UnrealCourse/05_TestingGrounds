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

void ATile::SpawnAIPawns(TSubclassOf<APawn> ToSpawn, int MinSpawn, int MaxSpawn, float Radius, float HeightOffset)
{
	TArray<FSpawnPoint> SpawnPoints = RandomSpawnPoints(MinSpawn, MaxSpawn, Radius, 1, 1);
	for (FSpawnPoint SpawnPoint : SpawnPoints)
	{
		SpawnAI(ToSpawn, SpawnPoint, HeightOffset);
	}
}

void ATile::PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn, float Radius, float MinScale, float MaxScale) {
	TArray<FSpawnPoint> SpawnPoints = RandomSpawnPoints(MinSpawn, MaxSpawn, Radius, MinScale, MaxScale);
	for (FSpawnPoint SpawnPoint : SpawnPoints)
	{
		PlaceActor(ToSpawn, SpawnPoint);
	}
}

TArray<FSpawnPoint> ATile::RandomSpawnPoints(int MinSpawn, int MaxSpawn, float Radius, float MinScale, float MaxScale) {
	int NumberToSpawn = FMath::RandRange(MinSpawn, MaxSpawn);
	TArray<FSpawnPoint> SpawnTransforms;
	for (size_t i = 0; i < NumberToSpawn; i++)
	{
		FVector SpawnLocation;
		float RandomScale = FMath::RandRange(MinScale, MaxScale);
		bool found = FindEmptyLocation(SpawnLocation, Radius * RandomScale);
		if (found) {
			float RandomRotation = FMath::RandRange(-180.f, 180.f);
			FSpawnPoint SpawnPoint;
			SpawnPoint.Location = SpawnLocation;
			SpawnPoint.Rotation = RandomRotation;
			SpawnPoint.Scale = RandomScale;
			SpawnTransforms.Add(SpawnPoint);
		}
	}
	return SpawnTransforms;
}

bool ATile::FindEmptyLocation(FVector& OutLocation, float Radius) {
	FVector Min(0, -2000, 0);
	FVector Max(4000, 2000, 0);
	FBox Bounds(Min, Max);
	const int MAX_ATTEMPTS = 100;
	for (size_t i = 0; i < MAX_ATTEMPTS; i++)
	{
		FVector CandidatePoint = FMath::RandPointInBox(Bounds);
		if (CanSpawnAtLocation(CandidatePoint, Radius)) {
			OutLocation = CandidatePoint;
			return true;
		}
	}
	return false;
}

void ATile::PlaceActor(TSubclassOf<AActor> ToSpawn, FSpawnPoint SpawnPoint) {
	AActor* Spawned = GetWorld()->SpawnActor<AActor>(ToSpawn);
	if (Spawned != nullptr)
	{
		Spawned->SetActorRelativeLocation(SpawnPoint.Location);
		Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
		Spawned->SetActorRotation(FRotator(0, SpawnPoint.Rotation, 0));
		Spawned->SetActorScale3D(FVector(SpawnPoint.Scale));
	}
}

void ATile::SpawnAI(TSubclassOf<APawn> ToSpawn, FSpawnPoint SpawnPoint, float HeightOffset) {
	APawn* Spawned = GetWorld()->SpawnActor<APawn>(ToSpawn);
	if (Spawned != nullptr) {
		Spawned->SpawnDefaultController();
		Spawned->SetActorRelativeLocation(SpawnPoint.Location);
		Spawned->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
		Spawned->SetActorRotation(FRotator(0, SpawnPoint.Rotation, 0));
		Spawned->Tags.Add(FName("Enemy"));
	}
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

bool ATile::CanSpawnAtLocation(FVector Location, float Radius)
{
	FHitResult HitResult;
	FVector GlobalLocation = ActorToWorld().TransformPosition(Location);
	bool HasHit = GetWorld()->SweepSingleByChannel(
		HitResult,
		GlobalLocation,
		GlobalLocation,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(Radius)
	);
	return !HasHit;
}