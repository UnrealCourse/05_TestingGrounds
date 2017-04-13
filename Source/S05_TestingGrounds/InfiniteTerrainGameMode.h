// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/GameModeBase.h"
#include "S05_TestingGroundsGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API AInfiniteTerrainGameMode : public AS05_TestingGroundsGameMode
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Navigation")
	void PlaceNavMesh(const FTransform& Transform);

protected:
	virtual void BeginPlay() override;
	
	int32 CurrentVolumeIndex = 0;
	TArray<class ANavMeshBoundsVolume *> Volumes;

private: 
	void EnsureVolumesPopulated();
};
