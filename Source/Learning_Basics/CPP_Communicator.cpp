// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_Communicator.h"
#include "Runtime/Engine/Classes/Engine/World.h"

// Sets default values
ACPP_Communicator::ACPP_Communicator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//UE_LOG(LogTemp, Warning, TEXT("My Root is: %s"), *GetName());

	UCPP_Participant* Participant = CreateDefaultSubobject<UCPP_Participant>(TEXT("Participant"));

	MyParticipant = Participant;

	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("MyRoot"));

	int Amount = FMath::RandRange(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("CPP_Communicator is being constucted."));

	//UWorld* MyWorld = GetWorld();

	//if (MyWorld)
	//{
	//	for (int32 i = 0; i < 14; i++)
	//	{
	//		//Spawn Objects
	//		UMyUObject* MyObject = NewObject<UMyUObject>();

	//		MyObject->TestInt += i;
	//		MyObjects.Add(MyObject);
	//	}
	//}
}

// Called when the game starts or when spawned
void ACPP_Communicator::BeginPlay()
{
	Super::BeginPlay();

	MyObjects.Empty();

	UWorld* MyWorld = GetWorld();

	if (MyWorld)
	{
		for (int32 i = 0; i < 4; i++)
		{
			// Spawn Actors
			ACPP_Communicator* Communicator = this;
			AActor_Participant* MyActorParticipant = MyWorld->SpawnActor<AActor_Participant>(FVector(0.f, 0.f, 0.f), FRotator(0.f, 0.f, 0.f));

			FAttachmentTransformRules Rules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false);
			MyActorParticipant->AttachToActor(this, Rules);

			MyActorParticipant->TestInt = i;

			ActorParticipants.Add(MyActorParticipant);

			//Spawn Objects
			UMyUObject* MyObject = NewObject<UMyUObject>();

			MyObject->TestInt += i;
			MyObjects.Add(MyObject);


		}
	}
	//Increase int of UObjects -> It will be saved even after stopping playmode (unless they are created outside of constructor).
	for (int32 i = 0; i < (MyObjects.Num()-1); i++)
	{
		MyObjects[i]->TestInt++;
	}


	/*if (IsLead && IsValid(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("I am the Lead and there should be no other!"));
		ACPP_Communicator *OtherComm = Cast<ACPP_Communicator>(OtherActor);
		if (OtherComm)
		{
			UE_LOG(LogTemp, Warning, TEXT("I see you, other Communicator, what is the name of your participant?"));

			OtherComm->GiveParticipantName();
		}
	}*/
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

