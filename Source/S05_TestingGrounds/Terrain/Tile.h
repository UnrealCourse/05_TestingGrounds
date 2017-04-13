// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Tile.generated.h"

struct FSpawnPoint
{
	FVector Location;
	float Rotation;
	float Scale;
};

UCLASS()
class S05_TESTINGGROUNDS_API ATile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATile();

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn = 1, int MaxSpawn = 1, float Radius = 500, float MinScale = 1, float MaxScale = 1);
	
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnAIPawns(TSubclassOf<APawn> ToSpawn, int MinSpawn, int MaxSpawn, float Radius, float HeightOffset = 100);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	TArray<FSpawnPoint> RandomSpawnPoints(int MinSpawn, int MaxSpawn, float Radius, float MinScale, float MaxScale);

	bool FindEmptyLocation(FVector& OutLocation, float Radius);

	void PlaceActor(TSubclassOf<AActor> ToSpawn, FSpawnPoint SpawnPoints);

	void SpawnAI(TSubclassOf<APawn> ToSpawn, FSpawnPoint SpawnPoint, float HeightOffset);

	bool CanSpawnAtLocation(FVector Location, float Radius);
	
};
