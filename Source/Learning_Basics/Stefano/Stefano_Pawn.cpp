// Fill out your copyright notice in the Description page of Project Settings.

#include "Stefano_Pawn.h"
#include "Components/InputComponent.h"

// Sets default values
AStefano_Pawn::AStefano_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(Mesh);
	Camera->SetRelativeLocation(FVector(-600.f, 0.f, 200.f));
	Camera->SetRelativeRotation(FRotator(-15.f, 0.f, 0.f));
}

// Called when the game starts or when spawned
void AStefano_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStefano_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move(DeltaTime);
}

// Called to bind functionality to input
void AStefano_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveX", this, &AStefano_Pawn::SetMoveInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AStefano_Pawn::DoJump);
}

void AStefano_Pawn::SetMoveInput(float Input)
{
	//UE_LOG(LogTemp, Warning, TEXT("MoveInput set to: %f"), Input);

	MoveInput = Input;
}

void AStefano_Pawn::Move(float DeltaTime)
{
	const float MoveValue = MoveInput * MoveSpeed;

	const FVector Movement = FVector(0.f, MoveValue, Gravity) * DeltaTime;
	//const FVector Movement = FVector(0.f, MoveValue, 0.f) * DeltaTime;

	//if (Movement.SizeSquared() > 0.0f)
	//{
	//	const FRotator Rot = GetActorRotation();
	//	RootComponent->MoveComponent(Movement,Rot ,true);
	//}

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = GetActorRotation();

		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}
}

void AStefano_Pawn::DoJump()
{
}

void AStefano_Pawn::OnCollision(AActor * SelfActor, AActor * OtherActor, FVector NormalImpulse, const FHitResult & Hit)
{
}

