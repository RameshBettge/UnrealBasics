// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"
#include "MyCharacter_CPP.generated.h"

UCLASS()
class LEARNING_BASICS_API AMyCharacter_CPP : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//UPROPERTY(EditAnywhere)
	UCapsuleComponent* MyCapsuleComponent;

	void SetMove(float value);
	
	void ApplyMove(float deltaTime);

	void DoJump();
	void DoStopJump();

	UFUNCTION()
	void MyOnCollision(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void SimpleMyOnCollision();
	
	float MoveVal;

	UPROPERTY(EditAnywhere)
		float SpeedMultiplicator;


};
