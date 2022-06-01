// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySlotWidget.h"
#include "InventoryWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

/*
bool UInventorySlotWidget::AddItem(const FSlotInfo& InSlot, const FItemInfo& Info)
{
	/*if (bHasItem)
	{
		return false;
	}

	if (ItemImage)
	{
		ItemImage->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		ItemImage->SetBrushFromTexture(Info.Icon.LoadSynchronous());
	}

	if (CountText)
	{
		CountText->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		CountText->SetText(FText::FromString(FString::FromInt(InSlot.Count)));
		Item.Count = InSlot.Count;
	}

	bHasItem = true;
	Item = InSlot;

	return true;#1#
}

void UInventorySlotWidget::Clear()
{
	if (!bHasItem)
	{
		return;
	}

	if (ItemImage)
	{
		ItemImage->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (CountText)
	{
		CountText->SetVisibility(ESlateVisibility::Collapsed);
	}

	bHasItem = false;
	Item = FSlotInfo();
}

UInventoryComponent* UInventorySlotWidget::GetParentInventory() const
{
}

FReply UInventorySlotWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (bCanDrag && bHasItem && InMouseEvent.IsMouseButtonDown(EKeys::LeftMouseButton))
	{
		return UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton).NativeReply;
	}

	return FReply::Handled();
	//return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}

void UInventorySlotWidget::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
	UDragDropOperation*& OutOperation)
{
	OutOperation = UWidgetBlueprintLibrary::CreateDragDropOperation(UDragDropOperation::StaticClass());
	if (OutOperation)
	{
		OutOperation->DefaultDragVisual = this;
	}
	else
	{
		Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
	}
	//Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
}

bool UInventorySlotWidget::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	if (InOperation && InOperation->DefaultDragVisual && InOperation->DefaultDragVisual!=this)
	{
		auto* FromSlot = Cast<UInventorySlotWidget>(InOperation->DefaultDragVisual);
		if (FromSlot)
		{
			//OnItemDrop.Broadcast(FromSlot, this);
			return true;
		}
	}
	return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
	//return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
}
*/
void UInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();
}

void UInventorySlotWidget::SetValues(FItemInfo InItemInfo, FSlotInfo InSlotInfo)
{
	SlotInfo=InSlotInfo;
	ItemInfo=InItemInfo;

	CountText->SetText(FText::AsNumber(SlotInfo.Count));
	ItemImage->SetBrushFromTexture(ItemInfo.Icon.LoadSynchronous());
}
