// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/// Forward declarations
class UTankTrack;

/**
 * Responsible for driving the tank tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKBATTLE_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
    UFUNCTION(BlueprintCallable, Category = Setup)
        void initialize(UTankTrack* leftTrack, UTankTrack* rightTrack);
    UFUNCTION(BlueprintCallable, Category = Movement)
        void intendMoveForward(float intention);
    UFUNCTION(BlueprintCallable, Category = Movement)
        void intendTurnRight(float intention);
private:
    UTankTrack* leftTrack = nullptr;
    UTankTrack* rightTrack = nullptr;
};
