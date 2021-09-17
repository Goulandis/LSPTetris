// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CCube.generated.h"

UCLASS()
class LSPTETRISCLIENT_API ACCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACCube();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//ConstructorHelpers::FObjectFinder<UMaterial> CCubeMat(TEXT("Material'/Game/SenceMaterial.SenceMaterial'"));
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
