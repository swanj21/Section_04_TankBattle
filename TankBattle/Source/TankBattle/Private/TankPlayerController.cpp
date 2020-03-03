// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {
    Super::BeginPlay();

    auto controlledTank = getControlledTank();

    if (!controlledTank) {
        UE_LOG(LogTemp, Warning, TEXT("No player tank currently controlled"))
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Currently controlled player tank is %s"), *controlledTank->GetName())
    }
}

void ATankPlayerController::Tick(float deltaTime) {
    Super::Tick(deltaTime);

    aimTowardsCrosshair();
}

void ATankPlayerController::aimTowardsCrosshair() {
    if (!getControlledTank()) {
        return;
    }

    FVector hitLocation; /// OUT parameter

    if (getSightRayHitLocation(hitLocation)) {
        getControlledTank()->aimAt(hitLocation);
    }
}

ATank* ATankPlayerController::getControlledTank() const {
    return Cast<ATank>(GetPawn());
}

bool ATankPlayerController::getSightRayHitLocation(FVector& hitLocation) {
    /// Find the crosshair position
    int32 viewportSizeX, viewportSizeY;
    GetViewportSize(viewportSizeX, viewportSizeY); /// Both are OUT params

    auto screenLocation = FVector2D(viewportSizeX * crosshairXLocation, viewportSizeY * crosshairYLocation);

    /// De-project the screen position of the crosshair to a world direction
    FVector lookDirection;

    if (getLookDirection(screenLocation, lookDirection)) {
        getLookVectorHitLocation(lookDirection, hitLocation);
    }

    return true;
}

bool ATankPlayerController::getLookDirection(FVector2D screenLocation, FVector& lookDirection) const {
    FVector cameraWorldLocation;

    return DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, cameraWorldLocation, lookDirection);
}

bool ATankPlayerController::getLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const {
    FHitResult hitResult;

    auto startLocation = PlayerCameraManager->GetCameraLocation();
    auto endLocation = startLocation + (lookDirection * lineTraceRange);

    if (GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECollisionChannel::ECC_Visibility)) {
        hitLocation = hitResult.Location;
        return true;
    }
    hitLocation = FVector(0);
    return false;
}