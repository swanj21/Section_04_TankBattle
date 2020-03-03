// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * Class for the turret component of a Tank object.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
    void rotate(float relativeSpeed);

private:
    UPROPERTY(EditAnywhere, Category = Setup)
        float maxDegreesPerSecond = 5;
};
