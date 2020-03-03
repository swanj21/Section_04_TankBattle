// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
    // -1 is max downward movement, 1 is max upward movement
    void elevate(float relativeSpeed);

private:
    UPROPERTY(EditAnywhere, Category = Setup)
        float maxDegreesPerSecond = 5;
    UPROPERTY(EditAnywhere, Category = Setup)
        float maxElevationDegrees = 40;
    UPROPERTY(EditAnywhere, Category = Setup)
        float minElevationDegrees = 0;
};
