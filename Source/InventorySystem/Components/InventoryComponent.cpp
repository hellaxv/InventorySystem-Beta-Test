// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

#include <stdbool.h>

#include "InventorySystem/InventorySystemGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

}

void UInventoryComponent::AddItem(FSlotInfo SlotInfo)
{
	int32 FoundIndex = SearchFreeStack(SlotInfo.Id);
	if (FoundIndex >=0 )
	{
		Items[FoundIndex].Count += SlotInfo.Count;
	}
	else
	{
		FoundIndex=SearchEmptySlot();
		if (FoundIndex>=0)
		{
			Items[FoundIndex] = SlotInfo;
		}
		else
		{
			Items.Add(SlotInfo);
		}
	}
}

void UInventoryComponent::AddItemAtIndex(int32 Index, FSlotInfo SlotInfo)
{
	if (Items[Index].Count>0)
	{
		Items[Index].Count += SlotInfo.Count;
	}
}

bool UInventoryComponent::RemoveItemAtIndex(int32 Index, int32 Count)
{
	if (Count>0 &&! IsSlotEmpty(Index))
	{
		if (Count >= GetAmountAtIndex(Index))
		{
			Items.RemoveAt(Index);
		}
		else
		{
			Items[Index].Count -= Count;
		}
		return true;
	}
	return false;
}


int32 UInventoryComponent::SearchFreeStack(FName ItemID)
{
	int32 Index = -1;
	for (int32 i=0; i<Items.Num(); i++)
	{
		if (Items[i].Id == ItemID)
		{
			Index = i;
			break;
		}
	}
	return Index;
}


void UInventoryComponent::GetSlotInfo(int32 Index, bool& bIsEmpty, FSlotInfo SlotInfo)
{
	if (Items[Index].Count>-1)
	{
		bIsEmpty=false;
		SlotInfo=Items[Index];
	}
	else
	{
		bIsEmpty=true;
	}
}

int32 UInventoryComponent::SearchEmptySlot()
{
	int32 Index = -1;
	for (int32 i=0; i<Items.Num(); i++)
	{
		if (Items[i].Count<=0)
		{
			Index = i;
			break;
		}
	}
	return Index;
}

bool UInventoryComponent::IsSlotEmpty(int32 Index)
{
	if (Items[Index].Count >0)
	{
		return false;
	}
	return true;
}

FItemInfo UInventoryComponent::GetItemInfo(FName ItemID)
{
	return Cast<AInventorySystemGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->GetItemInfo(ItemID);
}


