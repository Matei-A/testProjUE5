// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy_Default.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values for this component's properties
UEnemy_Default::UEnemy_Default()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UEnemy_Default::BeginPlay()
{
	Super::BeginPlay();

	// ...
	GEngine->AddOnScreenDebugMessage(-4, 3, FColor::Cyan, TEXT("Enemy component spawned"));


	//auto loc = UKismetMathLibrary::RandomPointInBoundingBox(GetAttachParent()->GetComponentLocation(), FVector(4000, 4000, 4000));
	//SetWorldLocation(loc);

}


// Called every frame
void UEnemy_Default::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEnemy_Default::Init(FVector loc)
{
	SetWorldLocation(loc);
}

