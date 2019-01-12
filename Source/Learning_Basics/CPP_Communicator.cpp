// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Communicator.h"

// Sets default values
ACPP_Communicator::ACPP_Communicator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//UE_LOG(LogTemp, Warning, TEXT("My Root is: %s"), *GetName());

	UCPP_Participant* Participant = CreateDefaultSubobject<UCPP_Participant>(TEXT("Participant"));

	MyParticipant = Participant;
}

// Called when the game starts or when spawned
void ACPP_Communicator::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Participants name: %s"), *MyParticipant->ParticipantName);
}

// Called every frame
void ACPP_Communicator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

