// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacter_CPP.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"


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

	// Gets a component and binds MyOnCollision() to it's Hit event, which is like Unity's OnCollisionEnter
	MyCapsuleComponent = Cast<UCapsuleComponent>(GetComponentByClass(UCapsuleComponent::StaticClass()));
	if (MyCapsuleComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("My Capsule component is: %s"), *MyCapsuleComponent->GetName());
		MyCapsuleComponent->OnComponentHit.AddDynamic(this, &AMyCharacter_CPP::MyOnCollision);

		// Also bind function to BeginOverlap. It is like Unity's OnTriggerEnter.
		MyCapsuleComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyCharacter_CPP::OnMyOverlap);
		MyCapsuleComponent->OnComponentEndOverlap.AddDynamic(this, &AMyCharacter_CPP::OnMyEndOverlap);
	}

	//Call function which can be implemented in blueprint.
	this->ReceiveMyBlueprintImplementableEvent();
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

	// Bind input to Functions which are already implemented in ACharacter
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter_CPP::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter_CPP::StopJumping);
}

void AMyCharacter_CPP::SetMove(float value)
{
	MoveVal = value;
}

void AMyCharacter_CPP::ApplyMove(float deltaTime)
{
	float movement = MoveVal * deltaTime * SpeedMultiplicator;
	AddMovementInput(FVector::RightVector, movement);
}

void AMyCharacter_CPP::MyOnCollision(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("Hit something: %s"), *OtherActor->GetName());
}

void AMyCharacter_CPP::OnMyOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlapped with: %s"), *OtherActor->GetName());
}
void AMyCharacter_CPP::OnMyEndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Ended overlap with: %s"), *OtherActor->GetName());
}

////void AMyCharacter_CPP::ReceiveMyBlueprintNativeEvent()
////{
////}
//void AMyCharacter_CPP::ReceiveMyBlueprintNativeEvent_Internal()
//{
//}
//void AMyCharacter_CPP::ReceiveMyBlueprintNativeEvent_Implementation()
//{
//	UE_LOG(LogTemp, Warning, TEXT("Standard implementation of 'MyBlueprintNativeEvent'. Info is: '%s'"), *info);
//}



