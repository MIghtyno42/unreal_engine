// Fill out your copyright notice in the Description page of Project Settings.

#include "Redis_Connector.h"

Redis_Connector::Redis_Connector()
{
	UE_LOG(LogTemp, Warning, TEXT("Setting Up Redis Connection"));
	FIPv4Address ip;
	ip = FIPv4Address(192, 168, 0, 112);
	TSharedRef<FInternetAddr> addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	addr->SetIp(ip.Value);
	addr->SetPort(6379);
	ConnectionSocket = FTcpSocketBuilder("Redis_Socket").AsReusable();
	bool connected = ConnectionSocket->Connect(*addr);
	if (connected) {
		UE_LOG(LogTemp, Warning, TEXT("Connected!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("NOT Connected!"));

	}
}

Redis_Connector::~Redis_Connector()
{
}
