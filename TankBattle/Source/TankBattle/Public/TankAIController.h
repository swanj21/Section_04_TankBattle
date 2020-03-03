// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/// Forward declarations
class ATank;

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
    void Tick(float deltaTime) override;
	
public:
    void BeginPlay() override;

    ATank* getControlledTank() const;

    ATank* getPlayerTank() const;
};
