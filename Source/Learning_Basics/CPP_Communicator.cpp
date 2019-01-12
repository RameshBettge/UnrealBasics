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

	UE_LOG(LogTemp, Warning, TEXT("CPP_Communicator is being constucted."));
}

// Called when the game starts or when spawned
void ACPP_Communicator::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(MyParticipant))
	{
		UE_LOG(LogTemp, Warning, TEXT("Participants name: %s"), *MyParticipant->ParticipantName);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("There is no Participant."));
	}

	if (IsLead && IsValid(OtherActor)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("I am the Lead and there should be no other!"));
		ACPP_Communicator *OtherComm = Cast<ACPP_Communicator>(OtherActor);
		if (OtherComm) 
		{
			UE_LOG(LogTemp, Warning, TEXT("I see you, other Communicator, what is the name of your participant?"));

			OtherComm->GiveParticipantName();
		}
	}
}

// Called every frame
void ACPP_Communicator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPP_Communicator::GiveParticipantName()
{
	if (IsValid(MyParticipant)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("My Participant's name is %s."), *MyParticipant->ParticipantName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("I don't have any :'("));
	}

}

