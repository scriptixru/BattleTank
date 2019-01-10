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

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0) 
	{
		//UE_LOG(LogTemp, Warning, TEXT("DamageAmount = %f, DamageToApply = %i"), DamageAmount, DamageToApply);
		//UE_LOG(LogTemp, Warning, TEXT("Tank died"));

		OnDeath.Broadcast();
	}

	return DamageToApply;
}




float ATank::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}

void ATank::BeginPlay() 
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}