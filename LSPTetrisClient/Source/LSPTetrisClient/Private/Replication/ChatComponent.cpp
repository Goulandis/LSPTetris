// Fill out your copyright notice in the Description page of Project Settings.


#include "Replication/ChatComponent.h"
#include "InputCoreTypes.h"
#include "Net/UnrealNetwork.h"
#include "Kismet/GameplayStatics.h"
#include "UI/LSPCompoundWidget.h"
#include "Manager/LSPTetrisGameInstance.h"

// Sets default values for this component's properties
UChatComponent::UChatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
	// ...
}


// Called when the game starts
void UChatComponent::BeginPlay()
{
	Super::BeginPlay();
	playerPtr = GetWorld()->GetFirstPlayerController();
	//UClass* widget = LoadClass<UUserWidget>(NULL, TEXT("WidgetBlueprint'/Game/Map/Chat.Chat_C'"));
	Cube = LoadClass<AActor>(NULL, TEXT("Blueprint'/Game/Map/Cube.Cube_C'"));
	ULSPTetrisGameInstance* gi = NewObject<ULSPTetrisGameInstance>();
	if (gi)
	{
		UE_LOG(LogTemp, Error, TEXT("create LSPGameInstance successfully"));
	}
	else
	{
		UE_LOG(LogTemp,Error,TEXT("Failed to create LSPGameInstance"))
	}
	//if (!widget)
	//{
	//	UE_LOG(LogTemp, Error, TEXT("UClass is null"));
	//	return;
	//}
	//if (playerPtr)
	//{
	//	widgetPtr = CreateWidget<UUserWidget>(playerPtr, widget);
	//	//widgetPtr = MakeShareable(CreateWidget<UUserWidget>(playerController, widget));
	//	if (widget)
	//	{
	//		widgetPtr->AddToViewport();
	//	}
	//}	

	/*TSharedRef<LSPCompoundWidget> lspCompoundWidget = SNew(LSPCompoundWidget);
	UWorld* world = GetWorld();
	if (world)
	{
		UGameViewportClient* viewPortClient = world->GetGameViewport();
		viewPortClient->AddViewportWidgetContent(lspCompoundWidget);
	}*/
}


// Called every frame
void UChatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (playerPtr->IsInputKeyDown(EKeys::LeftMouseButton) && this->GetOwner() == UGameplayStatics::GetPlayerPawn(GetWorld(),0))
	{
		SpwanCube();
	}
	SwitchTextRenderColor();
	//NetMulticastSetTextRenderColor(NULL);
}

void UChatComponent::SwitchTextRenderColor_Implementation()
{
	if (GetWorld()->IsServer())
	{
		if (cubeCount >= cubeCountTotal)
		{
			cubeCount = 0;
			TArray<UTextRenderComponent*> comps;
			GetOwner()->GetComponents(comps);
			if (comps.Num() != 1)
			{
				return;
			}
			
			UTextRenderComponent* textRender = comps[0];
			//textRender->SetTextRenderColor(TextColor);
			NetMulticastSetTextRenderColor(textRender);
		}
	}
}

void UChatComponent::SpwanCube_Implementation()
{
	if (Cube && GetWorld())
	{
		GetWorld()->SpawnActor<AActor>(Cube, GetOwner()->GetActorTransform());
		cubeCount++;
	}
}

void UChatComponent::NetMulticastSetTextRenderColor_Implementation(UTextRenderComponent* textRender)
{
	textRender->SetTextRenderColor(TextColor);
}

void UChatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UChatComponent, cubeCountTotal);
}

void UChatComponent::OnRep_cubeCountTotal()
{
	if (cubeCountTotal >= 40)
	{
		FString msg = FString::FromInt(cubeCountTotal);
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, *msg);
	}
}
