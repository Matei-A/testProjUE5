// Fill out your copyright notice in the Description page of Project Settings.


#include "NeonCharacter.h"

// Sets default values
ANeonCharacter::ANeonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANeonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANeonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANeonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &ANeonCharacter::Shoot);
}

void ANeonCharacter::Shoot()
{
	GEngine->AddOnScreenDebugMessage(0, 10, FColor::Red, "Shoot");
}

