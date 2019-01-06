// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// How close can the AI tank get
	UPROPERTY(EditDefaultsOnly, Category = "Setup") // Consider EditDefaultsOnly
	float AcceptanceRadius = 8000.0f;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	
};
