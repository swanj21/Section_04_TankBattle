// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::setThrottle(float throttle) {
    // TODO: Clamp actual throttle value so player can't add more than we desire
    auto name = GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s throttle %f"), *name, throttle);

    /// Apply the force forward using the calculated throttle and max driving force
    auto forceApplied = GetForwardVector() * throttle * trackMaxDrivingForce;
    
    /// Returns an FVector of the location of the tracks
    auto forceLocation = GetComponentLocation();

    auto tankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
    tankRoot->AddForceAtLocation(forceApplied, forceLocation);
}