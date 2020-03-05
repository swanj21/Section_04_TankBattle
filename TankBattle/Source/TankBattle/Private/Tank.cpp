// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "Tank.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
    auto time = GetWorld()->GetTimeSeconds();
    UE_LOG(LogTemp, Warning, TEXT("Tank fires at time %f"), time);
}