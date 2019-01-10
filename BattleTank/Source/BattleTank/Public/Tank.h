// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declarations
// class UTankBarrel;
// class UTankTurret;
// class UTankAimingComponent;
// class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	//Called by the engine when actor damage is dealt  
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;
	
	//void AimAt(FVector HitLocation);


	

protected:
// 	UPROPERTY(BlueprintReadOnly)
// 	UTankAimingComponent* TankAmingComponent = nullptr;
	
// 	UPROPERTY(BlueprintReadOnly)
// 	UTankMovementComponent* TankMovementComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	ATank();

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;
	
	
	
};
