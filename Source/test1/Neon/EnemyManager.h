// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy_Default.h"
#include "EnemyManager.generated.h"

UCLASS()
class TEST1_API AEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	
	TArray<UEnemy_Default*> Enemies;

	float TimerInterval = 1.f;
	float timer = 0;
	int totalEnemiesSpawned = 0;
	bool spawned = false;
public:

	void AddEnemy();
};
