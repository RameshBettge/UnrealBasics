// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Participant.h"
#include "Actor_Participant.h"
#include "MyUObject.h"
#include "CPP_Communicator.generated.h"


UCLASS()
class LEARNING_BASICS_API ACPP_Communicator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPP_Communicator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UCPP_Participant *MyParticipant = nullptr;

	UPROPERTY(EditAnywhere)
		bool IsLead = false;

	UPROPERTY(EditAnywhere)
	AActor* OtherActor = nullptr;

	void GiveParticipantName();

	UPROPERTY(EditAnywhere)
		TArray<AActor_Participant*> ActorParticipants;

	UPROPERTY(EditAnywhere)
	TArray<UMyUObject*> MyObjects;
};
