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
	UStaticMeshComponent* staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	staticMesh->SetupAttachment(RootComponent);
	if (MeshAsset.Succeeded())
	{
		//SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		staticMesh->SetStaticMesh(Asset);
		//staticMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 270.0f));

		staticMesh->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
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
}



// Called every frame
void ALeviathan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (reset) {
		FVector start(0);
		SetActorLocation(start, false);
		reset = false;
	}
	FVector newLocation = location;
	FRotator newRotation = rotation;
	
	newLocation.X = updatePos(location.X, targetLinear.X, movementSpeed, DeltaTime);
	newLocation.Y = updatePos(location.Y, targetLinear.Y, movementSpeed, DeltaTime);
	newLocation.Z = updatePos(location.Z, targetLinear.Z, movementSpeed, DeltaTime);

	newRotation.Roll = updatePos(rotation.Roll, targetRotation.Roll, 50.0f, DeltaTime);
	newRotation.Pitch = updatePos(rotation.Pitch, targetRotation.Pitch, 50.0f, DeltaTime);
	newRotation.Yaw = updatePos(rotation.Yaw, targetRotation.Yaw, 50.0f, DeltaTime);

	SetActorLocation(newLocation, true);
	SetActorRotation(newRotation);
	location = GetActorLocation();
	rotation = GetActorRotation();
}
template <class T>
T ALeviathan::updatePos(T current, T target, T movement_speed, float DeltaTime) {
	int sign = 0;
	if (current < target) sign = 1;
	if (current > target) sign = -1;
	
	T newLocation = current + sign*movement_speed*DeltaTime;

	int after_sign = 0;
	if (newLocation < target) after_sign = 1;
	if (newLocation > target) after_sign = -1;

	if (after_sign != sign) newLocation = target;
	return newLocation;
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
	targetRotation.Roll = r;
}
void ALeviathan::setPitchTarget(float p) {
	targetRotation.Pitch = p;
}
void ALeviathan::setYawTarget(float y) {
	targetRotation.Yaw = y;
}
