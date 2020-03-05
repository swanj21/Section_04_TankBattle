// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::aimAt(FVector location, float launchSpeed) {
    if (!barrel || 
        !turret) {
        return;
    }

    FVector launchVelocity;
    FVector startLocation = barrel->GetSocketLocation(FName("Projectile"));

    bool hasAimSolution = UGameplayStatics::SuggestProjectileVelocity(
        this, 
        launchVelocity, 
        startLocation, 
        location, 
        launchSpeed,
        false,
        0,
        0,
        ESuggestProjVelocityTraceOption::DoNotTrace);

    if (hasAimSolution) {
        auto aimDirection = launchVelocity.GetSafeNormal();
        moveBarrelTowards(aimDirection);
        moveTurretTowards(aimDirection);
    }
}

void UTankAimingComponent::setBarrelReference(UTankBarrel* barrelToSet) {
    if (!barrelToSet) { 
        return; 
    }
    barrel = barrelToSet;
}

void UTankAimingComponent::setTurretReference(UTankTurret* turretToSet) {
    if (!turretToSet) {
        return;
    }
    turret = turretToSet;
}

void UTankAimingComponent::moveBarrelTowards(FVector aimDirection) {
    /// Work out difference b/w current rotation and aim direction
    auto barrelRotator = barrel->GetForwardVector().Rotation();
    auto aimAsRotator = aimDirection.Rotation();
    auto deltaRotator = aimAsRotator - barrelRotator;
    barrel->elevate(deltaRotator.Pitch);
}

void UTankAimingComponent::moveTurretTowards(FVector aimDirection) {
    auto turretRotator = turret->GetComponentRotation();
    auto aimAsRotator = aimDirection.Rotation();
    auto deltaRotator = aimAsRotator - turretRotator;
    turret->rotate(deltaRotator.Yaw);
}