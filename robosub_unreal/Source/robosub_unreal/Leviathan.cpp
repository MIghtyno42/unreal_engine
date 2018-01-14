// Fill out your copyright notice in the Description page of Project Settings.

#include "Leviathan.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ALeviathan::ALeviathan()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));


	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Game/model/RobosubModel1.RobosubModel1'"));
	UStaticMesh* Asset = MeshAsset.Object;

	// Create and position a mesh component so we can see where our sphere is
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	SphereVisual->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
	if (SphereVisualAsset.Succeeded())
	{
		//SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		SphereVisual->SetStaticMesh(Asset);

		//SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, 90.0f));
		//SphereVisual->SetWorldScale3D(FVector(0.8f));
	}



	// Use a spring arm to give the camera smooth, natural-feeling motion.
	USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->RelativeRotation = FRotator(-45.f, 90.f, 0.f);
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	// Create a camera and attach to our spring arm
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	reset = true;
}

// Called when the game starts or when spawned
void ALeviathan::BeginPlay()
{
	Super::BeginPlay();
	targetLinear.X = 10;
}



// Called every frame
void ALeviathan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (reset) {
		FVector start(0);
		SetActorLocation(start, false);
		UE_LOG(LogTemp, Warning, TEXT("Robosub Reset"));
		reset = false;
	}
	FVector newLocation = location;
	if (targetLinear.X != location.X) {
		UE_LOG(LogTemp, Warning, TEXT("Moving X %f"), movementSpeed * DeltaTime);
		newLocation.X += movementSpeed * DeltaTime;
	}

	if (targetLinear.Y != location.Y) {
		newLocation.Y += movementSpeed * DeltaTime;
	}

	if (targetLinear.Z != location.Z) {
		newLocation.Z += movementSpeed * DeltaTime;
	}
	SetActorLocation(newLocation, true);
	location = GetActorLocation();
}

void ALeviathan::tripReset() {
	reset = true;
}

FVector ALeviathan::getLocation() {
	return location;
}

void ALeviathan::setXTarget(float x) {
	targetLinear.X = x;
}
void ALeviathan::setYTarget(float y) {
	targetLinear.Y = y;
}
void ALeviathan::setZTarget(float z) {
	targetLinear.Z = z;
}

void ALeviathan::setRollTarget(float r) {
	targetRotation.X = r;
}
void ALeviathan::setPitchTarget(float p) {
	targetRotation.Y = p;
}
void ALeviathan::setYawTarget(float y) {
	targetRotation.Z = y;
}
