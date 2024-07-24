// Fill out your copyright notice in the Description page of Project Settings.


#include "VR_Pawn.h"
#include "Camera/CameraComponent.h"
#include "MotionControllerComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AVR_Pawn::AVR_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	scene = CreateDefaultSubobject<USceneComponent>(TEXT("scene"));
	Camera  = CreateDefaultSubobject<UCameraComponent>(TEXT("Canera"));
	Camera->SetupAttachment(scene);
	
	LeftMotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftMotionController"));
	LeftMotionController->SetupAttachment(scene);
	LeftMotionController->SetTrackingSource(EControllerHand::Left);
	
	RightMotionController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightMotionController"));
	RightMotionController->SetupAttachment(scene);
	RightMotionController->SetTrackingSource(EControllerHand::Right);

	LeftHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftHand"));
	LeftHand->SetupAttachment(LeftMotionController);
	
	RightHand = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightHand"));
	RightHand->SetupAttachment(RightMotionController);
}

// Called when the game starts or when spawned
void AVR_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVR_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVR_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

