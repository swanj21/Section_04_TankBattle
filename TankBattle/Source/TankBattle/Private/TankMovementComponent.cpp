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

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {
    auto tankForwardDirection = GetOwner()->GetActorForwardVector().GetSafeNormal();
    auto aiForwardIntention = MoveVelocity.GetSafeNormal(); /// Unit vector for where the tank wants to move forward

    /// The dot product is using the cosine function to determine how much it will want to move forward
    intendMoveForward(FVector::DotProduct(tankForwardDirection, aiForwardIntention));

    /// The cross product is using the sin function to determine how much it will want to turn
    intendTurnRight(FVector::CrossProduct(tankForwardDirection, aiForwardIntention).Z);
}