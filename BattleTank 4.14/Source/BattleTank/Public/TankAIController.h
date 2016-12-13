// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */

class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:

	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 8000.0;
	
private:

	virtual void BeginPlay() override;

	// This method gets called when the AI tank gets possessed
	virtual void SetPawn(APawn* InPawn) override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	void OnPossessedTankDeath();
};
