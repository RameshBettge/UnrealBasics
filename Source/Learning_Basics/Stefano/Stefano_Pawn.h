// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Stefano_Pawn.generated.h"

UCLASS()
class LEARNING_BASICS_API AStefano_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AStefano_Pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *Mesh;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent *Camera;

	UPROPERTY(EditAnywhere, meta = (Category = "Movement"))
		float MoveSpeed = 700.f;

	UPROPERTY(EditAnywhere, meta = (Category = "Movement"))
		float YDrag = 0.05f;

	UPROPERTY(EditAnywhere, meta = (Category = "Movement|Jumping"))
		float JumpForce = 10000.f;

	UPROPERTY(EditAnywhere, meta = (Category = "Movement|Gravity"))
		float LightGravity = -100.f;

	UPROPERTY(EditAnywhere, meta = (Category = "Movement|Gravity"))
		float HeavyGravity = -300.f;

	UPROPERTY(VisibleAnywhere, meta = (Category = "Debugging"))
	bool IsGrounded;

	UPROPERTY(VisibleAnywhere, meta = (Category = "Debugging"))
		bool JumpPressed;

	FVector Velocity;

	float MoveInput;

	AActor* CollisionObject;

	void UpdateVelocity(float Input);

	void MoveHorizontal(float DeltaTime);
	void MoveVertical(float DeltaTime);

	void DoJump();
	void ReleaseJump();

	//void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);



};
