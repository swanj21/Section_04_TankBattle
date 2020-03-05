// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

// Rotate the turret at a given relativeSpeed
void UTankTurret::rotate(float relativeSpeed) {
    auto yawChange = FMath::Clamp<float>(relativeSpeed, -1, 1)
        * maxDegreesPerSecond
        * GetWorld()->DeltaTimeSeconds;

    auto newRotation = RelativeRotation.Yaw + yawChange;

    SetRelativeRotation(FRotator(0, newRotation, 0));
}