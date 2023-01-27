// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonPawn.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ANeonPawn::ANeonPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// this should be maybe in a component
void ANeonPawn::ReceiveParticleData_Implementation(const TArray<FBasicParticleData>& Data, UNiagaraSystem* NiagaraSystem, const FVector& SimulationPositionOffset)
{
	for (auto &particle : Data)
	{
		const FVector start = particle.Position;
		const FVector end = particle.Position + particle.Velocity * 0.05f;
		const float radius = particle.Size * 1.1f;

		TArray<AActor*> ActorToIgnore;
		ActorToIgnore.Add(this);

		FHitResult HitResult;
		
		UKismetSystemLibrary::SphereTraceSingle(GetWorld(), start, end, radius, ETraceTypeQuery::TraceTypeQuery1, false, ActorToIgnore, EDrawDebugTrace::None, HitResult, true);

		if (HitResult.HasValidHitObjectHandle())
		{
			auto hitActor = HitResult.HitObjectHandle.FetchActor();
			hitActor->TakeDamage(100, FDamageEvent(), GetController(), this);
		}
	}
}

// Called when the game starts or when spawned
void ANeonPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ANeonPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!MovementDirection.IsNearlyZero())
	{
		// TODO: USE THIS https://www.physicsclassroom.com/class/1DKin/Lesson-6/Kinematic-Equations (REDO MOVEMENT COMPLETELY) 
		// I think I need to do this, in order to be able to calculate rotations for the animation

		FVector directionNormalized = MovementDirection.GetClampedToSize(0, 1);

		// Move
		const FVector NewLocation = GetActorForwardVector() * directionNormalized.SizeSquared() * DeltaTime * MovementSpeed;
		FHitResult hitResult; 
		AddActorWorldOffset(NewLocation, true, &hitResult); // this checks collision too.. but how do i make it slide along the wall?
		
		if (hitResult.HasValidHitObjectHandle())
		{
			auto hitActor = hitResult.HitObjectHandle.FetchActor();
			if (hitActor->Tags.Contains("Enemy"))
			{
				hitActor->TakeDamage(1000, FDamageEvent(), GetController(), this);
			}
			if (hitActor->Tags.Contains("Pickup"))
			{
				hitActor->TakeDamage(1000, FDamageEvent(), GetController(), this);
			}
		}

		// Rotate - could be better?
		SetActorRotation(FMath::Lerp(GetActorRotation(), directionNormalized.Rotation(), 0.05f));
	}
}

// Called to bind functionality to input
void ANeonPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &ANeonPawn::Shoot);
	InputComponent->BindAxis(TEXT("Movement_Forward"), this, &ANeonPawn::MoveForward);
	InputComponent->BindAxis(TEXT("Movement_Right"), this, &ANeonPawn::MoveRight);

}

void ANeonPawn::MoveForward(float value)
{
	MovementDirection.X = FMath::Clamp(value, -1.0f, 1.0f);	
}

void ANeonPawn::MoveRight(float value)
{
	MovementDirection.Y = FMath::Clamp(value, -1.0f, 1.0f);
}

void ANeonPawn::Shoot()
{
}

