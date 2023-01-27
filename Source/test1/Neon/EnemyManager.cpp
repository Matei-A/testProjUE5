// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AEnemyManager::AEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
	

}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//timer += DeltaTime;
	//if (timer >= TimerInterval)
	//{
	//	timer = 0;
	//	AddEnemy();
	//}
	/*if (!spawned) 
	{
		for (int i = 0; i < 10000; i++)
		{
			AddEnemy();
		}
		spawned = true;
	}*/

	/*auto world = GetWorld();
	for(auto enemy : Enemies)
	{
		DrawDebugSphere(world, enemy->GetComponentLocation(), 20, 8, FColor::Red, false, 0);
	}*/

}

void AEnemyManager::AddEnemy()
{
	UEnemy_Default* NewComp = NewObject<UEnemy_Default>(this);

	if (!NewComp)
	{
		return;
	}

	NewComp->OnComponentCreated();
	NewComp->RegisterComponent();

	auto v = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), FVector(4000, 4000, 10));
	NewComp->Init(v);

	Enemies.Add(NewComp);
	totalEnemiesSpawned++;

}

