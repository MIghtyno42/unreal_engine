// Fill out your copyright notice in the Description page of Project Settings.


#include <cpp_redis/cpp_redis>
#pragma once
#include "CoreMinimal.h"
#pragma once
#include "GameFramework/Pawn.h"
#pragma once
#include "Leviathan.generated.h"

#ifdef _WIN32
#include <Winsock2.h>
#endif /* _WIN32 */

UCLASS()
class ROBOSUB_UNREAL_API ALeviathan : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ALeviathan();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called to reset the actor
	void tripReset();
	// Called to get the current Location of the actor
	FVector getLocation();
	//Functions to set X,Y,Z targets
	void setXTarget(float x);
	void setYTarget(float y);
	void setZTarget(float z);
	//Functions to set Roll, Pitch, Yaw
	void setRollTarget(float r);
	void setPitchTarget(float p);
	void setYawTarget(float y);

	UPROPERTY(EDITAnywhere, BlueprintReadWrite, Category = "Sub")
	float movementSpeed = 1;

private:
	bool reset;
	FVector location;
	
	FVector targetLinear;
	FVector targetRotation;
};
