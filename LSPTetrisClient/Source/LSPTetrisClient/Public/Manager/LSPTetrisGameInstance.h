// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "LSPTetrisGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class LSPTETRISCLIENT_API ULSPTetrisGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

		UFUNCTION(BlueprintCallable)
		void ConnectDs(FString ip);
		void Print(FString msg);
};
