// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NiagaraDataInterfaceExport.h"
#include "NeonPawn.generated.h"

UCLASS()
class TEST1_API ANeonPawn : public APawn, public INiagaraParticleCallbackHandler
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANeonPawn();

	void ReceiveParticleData_Implementation(const TArray<FBasicParticleData>& Data, UNiagaraSystem* NiagaraSystem, const FVector& SimulationPositionOffset) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private: 

	UPROPERTY(EditAnywhere, Category = "Debug")
		bool DebugMode = false;

	FVector MovementDirection;
	FVector LookDirection;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float MovementSpeed = 500.0f;
	UPROPERTY(EditAnywhere, Category = "Movement")
		float RotationSpeed = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Animation")
		float Inclination = 10.0f;

	void MoveForward(float value);
	void MoveRight(float value);
	void Shoot();
};
