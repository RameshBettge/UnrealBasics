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

	int Amount = FMath::RandRange(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("CPP_Communicator is being constucted with %d extra Participants."), Amount);

	GenerateMoreParticipants(Amount);

	//for (int32 i = 0; i > Amount; i++)
	//{
	//	UCPP_Participant* Participant = CreateDefaultSubobject<UCPP_Participant>(TEXT("Participant"));

		//MoreParticipants.Add(Participant);
	//}
}

// Called when the game starts or when spawned
void ACPP_Communicator::BeginPlay()
{
	Super::BeginPlay();

	//if (!MyParticipant) 
	//{
	//	MyParticipant = CreateDefaultSubobject<UCPP_Participant>(TEXT("YetAnotherParticipantName"));
	//}

	int Amount = FMath::RandRange(2, 8);
	//UE_LOG(LogTemp, Warning, TEXT("Number of participants (random nr): %d"), Amount);

	//GenerateMoreParticipants(Amount);
	UE_LOG(LogTemp, Warning, TEXT("Final number of extra participants in array: %d"), MoreParticipants.Num());


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

void ACPP_Communicator::GenerateMoreParticipants(int Amount)
{
	MoreParticipants.Empty();

	//for (int32 i = 0; i<1; i++)
	//{
		//UE_LOG(LogTemp, Warning, TEXT("Adding extra participant %d..."), (i+1));
	/*	FString NewName = FString("ExtraParticipant");
		NewName.Append(FString::FromInt(i));*/

	//UCPP_Participant* Participant = CreateDefaultSubobject<UCPP_Participant>(FName(*NewName));
	UCPP_Participant* Participant = CreateDefaultSubobject<UCPP_Participant>(TEXT("ExtraParticipant"));

		MoreParticipants.Add(Participant);

		//Participant = CreateDefaultSubobject<UCPP_Participant>(TEXT("AnotherExtraParticipant"));

		//MoreParticipants.Add(Participant);
		UE_LOG(LogTemp, Warning, TEXT("Number of extra participants in array: %d"), MoreParticipants.Num());
	//}
}

