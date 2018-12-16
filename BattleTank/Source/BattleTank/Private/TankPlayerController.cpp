// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

