// Fill out your copyright notice in the Description page of Project Settings.

#include "S05_TestingGrounds.h"
#include "InfiniteTerrainGameMode.h"
#include "EngineUtils.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"

void AInfiniteTerrainGameMode::BeginPlay() {
	Super::BeginPlay();

}

void AInfiniteTerrainGameMode::EnsureVolumesPopulated() {
	if (Volumes.Num() == 0) {
		for (TActorIterator<ANavMeshBoundsVolume> VolumeItr(GetWorld()); VolumeItr; ++VolumeItr) {
			UE_LOG(LogTemp, Warning, TEXT("Adding volume"));
			Volumes.Add(*VolumeItr);
		}

		if (Volumes.Num() != 2) {
			UE_LOG(LogTemp, Warning, TEXT("Should have 2 NavMesh volumes in the scene."));
		}
	}
}

void AInfiniteTerrainGameMode::PlaceNavMesh(const FTransform& Transform)
{
	EnsureVolumesPopulated();
	if (Volumes.Num() > 0) {
		ANavMeshBoundsVolume* Volume = Volumes[CurrentVolumeIndex];
		FVector VolumeLocation = Transform.GetLocation() + FVector(2000, 0, 0);
		Volume->SetActorLocation(VolumeLocation);
		GetWorld()->GetNavigationSystem()->Build();
		CurrentVolumeIndex = (CurrentVolumeIndex + 1) % 2;
	}
}
