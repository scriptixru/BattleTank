// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//No need to protect points as added at construction
	TankAmingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAmingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}
void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAmingComponent->SetTurretReference(TurretToSet);
}

void ATank::AimAt(FVector HitLocation)
{
	TankAmingComponent->AimAt(HitLocation, LaunchSpeed);


}

void ATank::Fire()
{
	
	if (!Barrel) { return; }

	//Spawn a projectile at the socket location on the barrel
	auto Projectile =  GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
		
		);
	Projectile->LaunchProjectile(LaunchSpeed);
}
