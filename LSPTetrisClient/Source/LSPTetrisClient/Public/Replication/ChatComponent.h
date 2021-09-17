// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/TextRenderComponent.h"
#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ChatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LSPTETRISCLIENT_API UChatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UChatComponent();
	UPROPERTY(BlueprintReadWrite)
	UUserWidget* widgetPtr;
	UPROPERTY(BlueprintReadWrite,Replicated)
	int cubeCount = 0;
	UPROPERTY(ReplicatedUsing = OnRep_cubeCountTotal, EditAnywhere, BlueprintReadWrite)
	int cubeCountTotal = 20;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FColor TextColor = FColor(0);
private:
	APlayerController* playerPtr;
	UClass* Cube;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UFUNCTION(Server, Reliable)
	void SpwanCube();
	UFUNCTION(Client, Reliable)
	void SwitchTextRenderColor();
	UFUNCTION(NetMulticast, Reliable)
	void NetMulticastSetTextRenderColor(UTextRenderComponent* textRender);
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	UFUNCTION()
	void OnRep_cubeCountTotal();
};
