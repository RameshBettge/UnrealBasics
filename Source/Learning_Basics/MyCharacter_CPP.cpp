// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter_CPP.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"


// Sets default values
AMyCharacter_CPP::AMyCharacter_CPP()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter_CPP::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyCharacter_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ApplyMove(DeltaTime);
}

// Called to bind functionality to input
void AMyCharacter_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveX", this, &AMyCharacter_CPP::SetMove);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter_CPP::DoJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter_CPP::StopJumping);
}

void AMyCharacter_CPP::SetMove(float value)
{
	MoveVal = value;

}

void AMyCharacter_CPP::ApplyMove(float deltaTime)
{
	float movement = MoveVal * deltaTime * SpeedMultiplicator;
	UE_LOG(LogTemp, Warning, TEXT("Ticking! %f"), movement);
	AddMovementInput(FVector::RightVector, movement);
}

void AMyCharacter_CPP::DoJump()
{
	Jump();
}

void AMyCharacter_CPP::DoStopJump()
{
	StopJumping();
}

