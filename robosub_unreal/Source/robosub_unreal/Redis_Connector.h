// Created by Cody Constine (cody.constine@colorado.edu)

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
	int get_key(FString key);
	int set_key(FString key, int set);
private:
	int parseReturnString(char * s);
	FSocket* ConnectionSocket;
	FIPv4Endpoint RemoteAddressForConnection;

};
