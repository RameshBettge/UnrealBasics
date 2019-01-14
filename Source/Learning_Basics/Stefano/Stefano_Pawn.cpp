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

	//Mesh->OnComponentHit.AddDynamic(this, &AStefano_Pawn::OnComponentHit);
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
	AddGravity(DeltaTime);
}

// Called to bind functionality to input
void AStefano_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveX", this, &AStefano_Pawn::UpdateVelocity);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AStefano_Pawn::DoJump);
}

void AStefano_Pawn::UpdateVelocity(float Input)
{
	Velocity.Y = Input;

	//UE_LOG(LogTemp, Warning, TEXT("Velocity is: %f"), Velocity);
}

void AStefano_Pawn::Move(float DeltaTime)
{
	const float MoveValue = Velocity.Y * DeltaTime;

	const FVector Movement = FVector(0.f, Velocity.Y, 0.f);

	const FRotator Rot = GetActorRotation();
	FHitResult Hit(1.f);
	if (Movement.SizeSquared() > 0.0f)
	{
		RootComponent->MoveComponent(Movement, Rot, true, &Hit);
	}
}

void AStefano_Pawn::DoJump()
{
	if (IsGrounded)
	{
		UE_LOG(LogTemp, Warning, TEXT("Jumping."));

		Velocity.Z = JumpForce;
	}
}

void AStefano_Pawn::AddGravity(float DeltaTime)
{
	Velocity.Z += Gravity * DeltaTime;

	const FRotator Rot = GetActorRotation();
	const FVector CurrGravity = FVector(0.f, 0.f, Velocity.Z * DeltaTime);
	FHitResult Hit(1.f);

	RootComponent->MoveComponent(CurrGravity, Rot, true, &Hit);

	IsGrounded = false;

	if (Hit.IsValidBlockingHit())
	{

		const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
		const FVector MyNormal = Hit.Normal;
		const FVector Deflection = FVector::VectorPlaneProject(CurrGravity, Normal2D) * (1.f - Hit.Time);
		RootComponent->MoveComponent(Deflection, Rot, true);

		//UE_LOG(LogTemp, Warning, TEXT("Normal2D = (%f, %f, %f)"), MyNormal.X, MyNormal.Y, MyNormal.Z);

		if (MyNormal.Z > 0.5f && Velocity.Z < 0.0f)
		{
			IsGrounded = true;
			Velocity.Z = 0.f;
		}
	}

	//UE_LOG(LogTemp, Warning, TEXT("Velocity.Z = %f"), Velocity.Z);

}

//void AStefano_Pawn::OnComponentHit(UPrimitiveComponent * HitComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
//{
//	UE_LOG(LogTemp, Warning, TEXT("Hit actor: %s"), *OtherActor->GetName());
//}

