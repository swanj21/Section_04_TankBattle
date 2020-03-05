// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

/// Forward declaration
class AProjectile;
class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;

UCLASS()
class TANKBATTLE_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable, Category = Setup)
        void setBarrelReference(UTankBarrel* barrelToSet);

    UFUNCTION(BlueprintCallable, Category = Setup)
        void setTurretReference(UTankTurret* turretToSet);

    void aimAt(FVector location);

    UFUNCTION(BlueprintCallable, Category = Firing)
        void fire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UTankAimingComponent* tankAimingComponent = nullptr;

private:
    UPROPERTY(EditAnywhere, Category=Firing)
        float launchSpeed = 4000;

    UPROPERTY(EditAnywhere, Category=Setup)
        TSubclassOf<AProjectile> projectileBlueprint;

    /// Local barrel reference for spawning the projectile
    UTankBarrel* barrel = nullptr;

    float reloadTimeSeconds = 3;
    double lastFireTime = 0;
};
