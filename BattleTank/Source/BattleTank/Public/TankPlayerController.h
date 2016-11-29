// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

class UTankAimingComponent;

/**
 * Responsible for helping the player aim.
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimingCompRef);

private:

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	
	// Start the tank moving the barrel and turret so that the shot
	// would hit where the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation=0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation=0.3333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
};
