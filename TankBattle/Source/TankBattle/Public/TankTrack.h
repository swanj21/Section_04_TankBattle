// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set maximum driving force and to apply forces
 * to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
    // Sets a throttle b/w -1 and 1
    UFUNCTION(BlueprintCallable, Category = Input)
        void setThrottle(float throttle);
	
    // Max force per track in Newtons
    UPROPERTY(EditDefaultsOnly)
        float trackMaxDrivingForce = 40000000;
};
