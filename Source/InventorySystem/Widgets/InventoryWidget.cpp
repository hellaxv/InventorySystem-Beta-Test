// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryWidget.h"

#include "InventorySystem/InventorySystemCharacter.h"
#include "InventorySystem/InventorySystemGameMode.h"

void UInventoryWidget::NativeConstruct()
{
	
	Super::NativeConstruct();

	InventoryRef = CastChecked<AInventorySystemCharacter>(GetOwningPlayerPawn())->InventoryComponent;
	if (InventoryRef)
	{
		InventoryRef->OnInventoryUpdated.AddDynamic(this, &ThisClass::InitializeInventory);
		InitializeInventory();
	}
}

void UInventoryWidget::InitializeInventory()
{
	
	if (!SlotWidgetClass)
	{
		return;
	}

	InventoryBox->ClearChildren();
	AInventorySystemGameMode* GM =  GetWorld()->GetAuthGameMode<AInventorySystemGameMode>();
	for (int32 i = 0; i < InventoryRef->Items.Num(); i++)
	{
		FItemInfo ItemInfo = GM->GetItemInfo(InventoryRef->Items[i].Id);
		UInventorySlotWidget* SlotWidget=CreateWidget<UInventorySlotWidget>(GetOwningPlayer(), SlotWidgetClass);
		SlotWidget->SetValues(ItemInfo, InventoryRef->Items[i]);
		InventoryBox->AddChildToWrapBox(SlotWidget);
	}
}
