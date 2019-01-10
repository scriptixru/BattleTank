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

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FTankDelegate);

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	//Called by the engine when actor damage is dealt  
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;
	
	//void AimAt(FVector HitLocation);

	// Return current health as percentage of starting health between 0 and 1
	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	FTankDelegate OnDeath;
	

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
	int32 CurrentHealth; //Initialised in BeginPlay() 
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
