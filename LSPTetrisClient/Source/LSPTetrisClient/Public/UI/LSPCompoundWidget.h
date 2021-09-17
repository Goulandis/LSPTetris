// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "CoreMinimal.h"

/**
 * 
 */

class LSPTETRISCLIENT_API LSPCompoundWidget //: public SCompoundWidget
{
public:
	LSPCompoundWidget();
	~LSPCompoundWidget();
private:
	TAttribute<FString> msg;
	FOnClicked ButtonClickedEvent;
//public:
//	SLATE_BEGIN_ARGS(LSPCompoundWidget)
//	{
//		_msg = TEXT("The Button");
//	}
//	SLATE_ATTRIBUTE(FString,msg)
//	SLATE_EVENT(FOnClicked, ButtonClickedEvent)
//	SLATE_END_ARGS()
//
//public:
//	void Contruct(const FArguments& InArg);
};
