// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "InventorySystem/GameData/ItemInfo.h"
#include "InventoryComponent.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORYSYSTEM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

/*
public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	*/
	//protected: 
	
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Equip")
	//TMap<int32, EEquipSlot> EquipSlots;

public:

	UInventoryComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FSlotInfo> Items;

	UFUNCTION(BlueprintCallable)
	void AddItem(FSlotInfo SlotInfo);

	UFUNCTION(BlueprintCallable)
	void AddItemAtIndex(int32 Index, FSlotInfo SlotInfo);

	UFUNCTION(BlueprintCallable)
	bool RemoveItemAtIndex(int32 Index, int32 Count);

	void GetSlotInfo(int32 Index, bool& bIsEmpty, FSlotInfo SlotInfo);

	int32 SlotMaxItems;

	int32 SearchFreeStack(FName ItemID);

	int32 GetAmountAtIndex(int32 Index){return Items[Index].Count;};

	int32 SearchEmptySlot();

	bool IsSlotEmpty(int32 Index);

	FItemInfo GetItemInfo(FName ItemID);
	
	UPROPERTY(BlueprintAssignable)
	FOnInventoryUpdated OnInventoryUpdated;
	
	
	
};



