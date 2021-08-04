// Fill out your copyright notice in the Description page of Project Settings.


#include "Manager/LSPTetrisGameInstance.h"
#include "GameFramework/Actor.h"

void ULSPTetrisGameInstance::ConnectDs(FString ip)
{
	GetWorld()->GetFirstPlayerController()->ClientTravel(ip, TRAVEL_Absolute); 
}

void ULSPTetrisGameInstance::Print(FString msg)
{
	if(Authority)
}
