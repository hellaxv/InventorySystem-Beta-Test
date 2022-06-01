// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InventorySlotWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/WrapBox.h"
#include "InventorySystem/GameData/ItemInfo.h"
#include "InventoryWidget.generated.h"

class UUniformGridPanel;
class UInventoryComponent;
/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()

	
public:

	virtual void NativeConstruct() override;

	
	UPROPERTY()
	UInventoryComponent* InventoryRef;
	//reference

	UFUNCTION(BlueprintCallable)
	void InitializeInventory();

	
	
protected:

	UPROPERTY(EditDefaultsOnly)
	int32 ItemsInRow = 5;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventorySlotWidget> SlotWidgetClass;

	UPROPERTY(BlueprintReadOnly, meta=(BindWidgetOptional))
	UWrapBox* InventoryBox;
	


};
