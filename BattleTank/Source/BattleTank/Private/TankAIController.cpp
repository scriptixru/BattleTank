// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
// #include "Tank.h"


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn(); // Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = GetPawn(); // Cast<ATank>(GetPawn());
	if (!ensure(PlayerTank && ControlledTank)) { return; }

	//Move towards the player 
	MoveToActor(PlayerTank, AcceptanceRadius);

	//Aim at the towards
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();

	AimingComponent->AimAt(PlayerTank->GetActorLocation());
	
	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire(); //TODO limit firing rate
	}
		
		

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}



