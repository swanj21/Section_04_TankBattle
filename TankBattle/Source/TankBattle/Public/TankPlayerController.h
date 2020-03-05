// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/// Forward declarations
class ATank;

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController {
    GENERATED_BODY()

public:
    void BeginPlay() override;
    void Tick(float deltaTime) override;

    void aimTowardsCrosshair();
    ATank* getControlledTank() const;

private:
    UPROPERTY(EditDefaultsOnly)
        float crosshairXLocation = .5f;
    UPROPERTY(EditDefaultsOnly)
        float crosshairYLocation = .3333f;
    UPROPERTY(EditDefaultsOnly)
        float lineTraceRange = 1000000; /// 10km, 1 million cm

    bool getSightRayHitLocation(FVector &hitLocation);
    bool getLookDirection(FVector2D screenLocation, FVector &lookDirection) const;
    bool getLookVectorHitLocation(FVector lookDirection, FVector& hitLocation) const;
};
