// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
//#include "TankBarrel.h"
//#include "Projectile.h"
// #include "TankAimingComponent.h"




// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//No need to protect points as added at construction
	//TankAmingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));
	
}

// Called when the game starts or when spawned
// void ATank::BeginPlay()
// {
// 	Super::BeginPlay();
// 	
// 	//TankAmingComponent = FindComponentByClass<UTankAimingComponent>();
// }


/*
void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAmingComponent)) { return; }
	TankAmingComponent->AimAt(HitLocation, LaunchSpeed);


}
*/

