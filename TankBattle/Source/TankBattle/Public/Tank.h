// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

/// Forward declaration
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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    UTankAimingComponent* tankAimingComponent = nullptr;

private:
    UPROPERTY(EditAnywhere, Category=Firing)
        float launchSpeed = 100000; /// TODO: Find a sensible default speed, then leave it to the designer(me) to tweak it.
};
