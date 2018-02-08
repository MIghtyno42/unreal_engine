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
		FRotator startRot(0);
		SetActorRotation(startRot);
		reset = false;
	}
	//redis set update block
	double xSet = redis.get_key(TEXT("x_set")) * 100;
	double ySet = redis.get_key(TEXT("y_set")) * 100;
	//x and y are the change in the sub frame locations
	double x = -1 * (last_x - xSet);
	double y = -1 * (last_y - ySet);
	//if no change then don't update the targets
	if (x  != 0 || y  != 0) {

		double yaw = FMath::DegreesToRadians(rotation.Yaw);
		//here is the change of frame
		// when yaw == 0
		// cos(0) = 1 sin(0) = 0 therefore  x=x y=y
		// when yaw == 90 deg
		// cos(90) = 0 sin(90) = 1 therefore x=y y=x
		targetLinear.X += x * cos(yaw) + y * sin(yaw);
		targetLinear.Y += x * sin(yaw) + y * cos(yaw);
	}
	last_x = xSet;
	last_y = ySet;
	
	targetLinear.Z = redis.get_key(TEXT("z_set")) * 100;
	targetRotation.Roll = FMath::RadiansToDegrees(redis.get_key(TEXT("roll_set")));
	targetRotation.Pitch = FMath::RadiansToDegrees(redis.get_key(TEXT("pitch_set")));
	targetRotation.Yaw = FMath::RadiansToDegrees(redis.get_key(TEXT("yaw_set")));

	//Position update block
	FVector newLocation = location;
	FRotator newRotation = rotation;

	newLocation.X += updatePos(location.X, targetLinear.X, movementSpeed, DeltaTime);
	newLocation.Y += updatePos(location.Y, targetLinear.Y, movementSpeed, DeltaTime);
	newLocation.Z += updatePos(location.Z, targetLinear.Z, movementSpeed, DeltaTime);

	newRotation.Roll += updatePos(rotation.Roll, targetRotation.Roll, 50.0f, DeltaTime);
	newRotation.Pitch += updatePos(rotation.Pitch, targetRotation.Pitch, 50.0f, DeltaTime);
	newRotation.Yaw += updatePos(rotation.Yaw, targetRotation.Yaw, 50.0f, DeltaTime);

	SetActorLocation(newLocation, true);
	SetActorRotation(newRotation);
	location = GetActorLocation();
	rotation = GetActorRotation();

	//redis position update block
	
}
template <class T>
T ALeviathan::updatePos(T current, T target, T movement_speed, float DeltaTime) {
	//get sign for movement
	int sign = 0;
	if (current < target) sign = 1;
	if (current > target) sign = -1;
	
	T newLocation = sign*movement_speed*DeltaTime;

	//check sign after movement
	int after_sign = 0;
	if (current+newLocation < target) after_sign = 1;
	if (current+newLocation > target) after_sign = -1;
	// if it changed we passed it and the movement should just be to set ourselves at the location
	if (after_sign != sign) newLocation = -1*(current-target);
	return newLocation;
}

void ALeviathan::tripReset() {
	reset = true;
}

FVector ALeviathan::getLocation() {
	return location;
}

FRotator ALeviathan::getRotation() {
	return rotation;
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
