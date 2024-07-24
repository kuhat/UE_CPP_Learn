// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AEnemy::AEnemy() : AttachStrength(500.0f), VerticalOffset(0.0f, 0.0f, 130.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = BoxComponent;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(BoxComponent);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetEnableGravity(false);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	FVector Direction = PlayerPawn->GetActorLocation() - GetActorLocation() + VerticalOffset;
	
	Direction = UKismetMathLibrary::Normal(Direction);
	Mesh->AddImpulse(AttachStrength*Direction);
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

