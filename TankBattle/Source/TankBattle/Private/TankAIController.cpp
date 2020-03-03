// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
    Super::BeginPlay();

    auto playerTank = getPlayerTank();

    if (!playerTank) {
        UE_LOG(LogTemp, Warning, TEXT("Player tank not found"))
    } else {
        UE_LOG(LogTemp, Warning, TEXT("Currently controlled Player tank is %s"), *playerTank->GetName())
    }
}

void ATankAIController::Tick(float deltaTime) {
    Super::Tick(deltaTime);
    if (getPlayerTank()) {
        /// Move towards player
        getControlledTank()->aimAt(getPlayerTank()->GetActorLocation());
        /// Fire if ready
    }
}

/// Get the currently controlled tank
ATank* ATankAIController::getControlledTank() const {
    return Cast<ATank>(GetPawn());
}

/// Find the tank that the player is using
ATank* ATankAIController::getPlayerTank() const {
    auto playerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
    if (!playerTank) {
        UE_LOG(LogTemp, Warning, TEXT("Could not find player controlled tank"));
        return nullptr;
    }
    return Cast<ATank>(playerTank);
}