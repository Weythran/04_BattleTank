// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float RelativeSpeed);
	
private:
	// -1 is max downward speed, +1 is max upward speed
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 15;
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = -2;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40;
};
