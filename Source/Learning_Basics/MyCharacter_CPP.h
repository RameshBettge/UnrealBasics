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

	UFUNCTION()
	void MyOnCollision(UPrimitiveComponent*	HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/*UFUNCTION()
		void OnMyOverlap(FComponentBeginOverlapSignature Signature);*/
	
	UFUNCTION()
		void OnMyOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult);

	UFUNCTION()
		void OnMyEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	float MoveVal;

	/*UFUNCTION(BlueprintNativeEvent, BlueprintCallable, meta = (DisplayName = "MyBlueprintNativeEvent"))
		void ReceiveMyBlueprintNativeEvent();*/

	UPROPERTY(EditAnywhere)
		float SpeedMultiplicator;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "MyBlueprintImplementableEvent"))
		void ReceiveMyBlueprintImplementableEvent();
};
