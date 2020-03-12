// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::setThrottle(float throttle) {
    // TODO: Clamp actual throttle value so player can't add more than we desire
    auto name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s throttle %f"), *name, throttle);
}