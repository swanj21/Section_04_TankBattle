// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::elevate(float relativeSpeed) {
    auto elevationChange = FMath::Clamp<float>(relativeSpeed, -1, 1) 
        * maxDegreesPerSecond 
        * GetWorld()->DeltaTimeSeconds;

    auto newElevationRaw = RelativeRotation.Pitch + elevationChange;
    auto elevation = FMath::Clamp<float>(newElevationRaw, minElevationDegrees, maxElevationDegrees);
    SetRelativeRotation(FRotator(elevation, 0, 0));
}