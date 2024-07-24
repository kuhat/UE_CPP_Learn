// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class LEARNCPP_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void HandleTimerFinished();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int numOfEnemies;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AEnemy> AEnemyClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HalfHorizontalOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HalfVerticalOffset;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HalfDepthOffset;
	
	FTimerHandle TimerHandle;
};
