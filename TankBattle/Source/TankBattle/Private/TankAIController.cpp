// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay() {
    Super::BeginPlay();

    playerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    controlledTank = Cast<ATank>(GetPawn());
}

void ATankAIController::Tick(float deltaTime) {
    Super::Tick(deltaTime);
    if (!playerTank || !controlledTank) {
        return;
    }

    MoveToActor(playerTank, acceptanceRadius); /// TODO: Check radius is in cm

    controlledTank->aimAt(playerTank->GetActorLocation());
    controlledTank->fire(); /// TODO: Don't fire every frame
}
