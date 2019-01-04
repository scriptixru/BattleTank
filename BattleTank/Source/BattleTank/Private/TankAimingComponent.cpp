// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false; 

	// ...
}

void UTankAimingComponent::Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	//if (!BarrelToSet || !TurretToSet) return;
	Barrel = BarrelToSet;	
	Turret = TurretToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	/*auto OurTankName = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s from %s"), *OurTankName, *HitLocation.ToString(), *BarrelLocation.ToString());*/
	if (!Barrel) { return; }

	FVector OutLaunchVelosity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	//const TArray<AActor*> ActorsToIgnore;
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelosity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0.f,
		0.f,
		ESuggestProjVelocityTraceOption::DoNotTrace
// 		,FCollisionResponseParams::DefaultResponseParam,
// 		ActorsToIgnore,
// 		true
	);
	if (bHaveAimSolution)
	{		
		auto AimDirection = OutLaunchVelosity.GetSafeNormal();
// 		auto TankName = GetOwner()->GetName();
// 		UE_LOG(LogTemp, Warning, TEXT("%s aming at %s"), *TankName, *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
// 		auto Time = GetWorld()->GetTimeSeconds();
// 		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solutions found"), Time);

	}
// 	else
// 	{
// 		auto Time = GetWorld()->GetTimeSeconds();
// 		UE_LOG(LogTemp, Warning, TEXT("%f: No aim solve found"), Time);
// 
// 	}
	// If no solution found do nothing
}
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	if (!Barrel || !Turret) { return; }

	// Work-out difference between current barrel rotation, and AimDirection 
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch); 
	Turret->Rotate(DeltaRotator.Yaw);
}


