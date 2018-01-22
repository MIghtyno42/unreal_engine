// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Networking.h"

/**
 * 
 */
class ROBOSUB_UNREAL_API Redis_Connector
{
public:
	Redis_Connector();
	~Redis_Connector();

	FSocket* ConnectionSocket;
	FIPv4Endpoint RemoteAddressForConnection;

};
