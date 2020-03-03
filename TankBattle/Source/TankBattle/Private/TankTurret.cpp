// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

// Just like a tank has a barrel, it also has a turret. 
// The barrel elevates, the turret rotates if necessary.

void UTankTurret::rotate(float relativeSpeed) {
    auto yawChange = FMath::Clamp<float>(relativeSpeed, -1, 1)
        * maxDegreesPerSecond
        * GetWorld()->DeltaTimeSeconds;

    auto newRotationRaw = RelativeRotation.Yaw + yawChange;
    auto finalRotation = FMath::Clamp<float>(newRotationRaw, -180, 180);

    SetRelativeRotation(FRotator(0, finalRotation, 0));
}