// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/LSPCompoundWidget.h"

LSPCompoundWidget::LSPCompoundWidget()
{
}

LSPCompoundWidget::~LSPCompoundWidget()
{
}

//BEGIN_FUNCTION_BUILD_OPTIMIZATION
//void LSPCompoundWidget::Contruct()
//{
//	
//	ChildSlot.VAlign(VAlign_Center).HAlign(HAlign_Center)
//		[
//			SNew(SButton)
//			.OnClicked(ButtonClickedEvent)
//			.Content()
//			[
//				SNew(STextBlock)
//				.Text_Lambda([this] {return FText::FromString(msg.Get()); })
//			]
//		];
//}
//BEGIN_FUNCTION_BUILD_OPTIMIZATION
