// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::initialize(UTankTrack* leftTrack, UTankTrack* rightTrack) {
    this->leftTrack = leftTrack;
    this->rightTrack = rightTrack;
}
void UTankMovementComponent::intendMoveForward(float intention) {
    if (!leftTrack || !rightTrack) {
        return;
    }
    leftTrack->setThrottle(intention);
    rightTrack->setThrottle(intention);
    /// TODO: Prevent double-speed due to dual control use(trigger and stick doubles speed)
}

void UTankMovementComponent::intendTurnRight(float intention) {
    if (!leftTrack || !rightTrack) {
        return;
    }
    leftTrack->setThrottle(intention);
    rightTrack->setThrottle(-intention);
}