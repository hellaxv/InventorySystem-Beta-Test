// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "InventorySystem/GameData/ItemInfo.h"


#include "InventorySlotWidget.generated.h"


class UInventoryWidget;
class UInventoryComponent;
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInventorySlotWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UImage* ItemImage;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidget))
	UTextBlock* CountText;

	virtual void NativeConstruct() override;

	//bool bHasItem = false;

	UPROPERTY(BlueprintReadOnly)
	FItemInfo ItemInfo;

	UPROPERTY(BlueprintReadOnly)
	FSlotInfo SlotInfo;
	
public:
	UFUNCTION(BlueprintCallable)
	void SetValues(FItemInfo InItemInfo, FSlotInfo InSlotInfo);
//public:

	/*bool HasItem() const {return bHasItem;}

	bool AddItem(const FSlotInfo& InSlot, const FItemInfo& Info);

	void Clear();

	const FSlotInfo& GetItem() const {return Item; }

	UPROPERTY(EditAnywhere)
	int32 IndexInInventory = INDEX_NONE;

	//FOnItemDrop OnItemDrop;

	UPROPERTY()
	UInventoryWidget* ParentInventoryWidget;
	
	UInventoryComponent* GetParentInventory() const;
	
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
		
protected:
	//virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;

	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;

	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;

	UPROPERTY(EditAnywhere)
	bool bCanDrag = true;*/
};
