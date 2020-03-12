// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "TankBarrel.h"

#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

    tankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Set the reference to the Barrel
void ATank::setBarrelReference(UTankBarrel* barrelToSet) {
    barrel = barrelToSet;
    tankAimingComponent->setBarrelReference(barrelToSet);
}

// Set the reference to the Turret
void ATank::setTurretReference(UTankTurret* turretToSet) {
    tankAimingComponent->setTurretReference(turretToSet);
}

void ATank::aimAt(FVector location) {
    tankAimingComponent->aimAt(location, launchSpeed);
}

void ATank::fire() {
    bool isReloaded = (GetWorld()->GetTimeSeconds() - lastFireTime) > reloadTimeSeconds;
    if (barrel && isReloaded) {
        /// Spawn a projectile from the 'projectile' socket location
        auto projectile = GetWorld()->SpawnActor<AProjectile>(
            projectileBlueprint,
            barrel->GetSocketLocation(FName("Projectile")),
            barrel->GetSocketRotation(FName("Projectile"))
            );

        projectile->launchProjectile(launchSpeed);

        lastFireTime = GetWorld()->GetTimeSeconds();
    }
}