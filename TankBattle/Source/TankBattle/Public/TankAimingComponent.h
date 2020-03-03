// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

/// Forward declaration
class UTankBarrel;
class UTankTurret;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKBATTLE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTankAimingComponent();
    void aimAt(FVector location, float launchSpeed);
    void setBarrelReference(UTankBarrel* barrelToSet);
    void setTurretReference(UTankTurret* turretToSet);

private:
    UTankBarrel* barrel = nullptr;
    UTankTurret* turret = nullptr;

    void moveBarrelTowards(FVector aimDirection);
    void moveTurretTowards(FVector aimDirection);
};
