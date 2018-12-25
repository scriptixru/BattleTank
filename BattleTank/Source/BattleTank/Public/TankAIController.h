// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called when the game starts or when spawned
	void BeginPlay() override;


private:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

	
	
	
	
};
