// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AEnemySpawner::AEnemySpawner() : numOfEnemies(5), SpawnTime(2.0f), HalfHorizontalOffset(500.0f), HalfVerticalOffset(300.0f), HalfDepthOffset(300.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AEnemySpawner::HandleTimerFinished, SpawnTime, true);
}

void AEnemySpawner::HandleTimerFinished()
{
	for(int i = 0; i < numOfEnemies;++i)
	{
		float HorizontalOffset = UKismetMathLibrary::RandomFloatInRange(-HalfHorizontalOffset, HalfHorizontalOffset);
		float VerticalOffset = UKismetMathLibrary::RandomFloatInRange(-HalfVerticalOffset, HalfVerticalOffset);
		float DepthOffset = UKismetMathLibrary::RandomFloatInRange(-HalfDepthOffset, HalfDepthOffset);
		FVector Location = GetActorLocation();
		Location.Y += HorizontalOffset;
		Location.Z += VerticalOffset;
		GetWorld()->SpawnActor<AEnemy>(AEnemyClass, Location, FRotator::ZeroRotator);
	}
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

