// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above this line

/// Forward declarations
/// Commented out due to lecture 169 changes
///class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

// Commented out due to lecture 160 refactoring
//	UFUNCTION(BlueprintCallable, Category = "Setup")
//	void SetBarrelReference(UTankBarrel* BarrelToSet);

// Commented out due to lecture 160 refactoring
//	UFUNCTION(BlueprintCallable, Category = "Setup")
//	void SetTurretReference(UTankTurret* TurretToSet);

//	Commented out due to lecture 169 changes
//	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

//	protected:
//	Commented out due to lecture 169 changes
//	UPROPERTY(BlueprintReadOnly)
//	UTankAimingComponent* TankAimingComponent = nullptr;

private:

	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// TODO remove once firing has been moved to AimingComponent
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 100000; // Sensible starting value of 1000 m/s

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint = nullptr;

	// Local barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr; // TODO Remove

	double LastFireTime = 0;
};
