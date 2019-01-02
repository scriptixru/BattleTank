// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{ 
		//Move towards the player 
		MoveToActor(PlayerTank, AcceptanceRadius);

		//Aim at the towards
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//Fire if ready
		ControlledTank->Fire(); //TODO limit firing rate

	}

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}



