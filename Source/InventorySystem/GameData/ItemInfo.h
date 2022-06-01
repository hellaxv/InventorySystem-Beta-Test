#pragma once
#include "Engine/DataTable.h"
#include "ItemInfo.generated.h"

UENUM()
enum class EItemType: uint8
{
	It_Misc,
	It_Currency,
	It_Equip,
	It_Consumable,
};

UENUM()
enum class EItemRarity: uint8
{
	Ir_Common,
	Ir_Rare,
	Ir_Epic,
};

class UInventoryCellWidget;

//DECLARE_MULTICAST_DELEGATE_TwoParams(FOnItemDrop, UInventorySlotWidget* /*from*/, UInventorySlotWidget* /*to*/)

USTRUCT(BlueprintType)
struct FItemInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category="General")
	FName Id;

	UPROPERTY(EditDefaultsOnly, Category="General")
	FText Name;

	UPROPERTY(EditDefaultsOnly, Category="Type")
	EItemType Type;

	UPROPERTY(EditDefaultsOnly, Category="Type")
	EItemRarity Rare;

	UPROPERTY(EditDefaultsOnly, Category="Visual")
	TSoftObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditDefaultsOnly, Category="Visual")
	TSoftObjectPtr<UStaticMesh> Mesh;
	
};

USTRUCT(BlueprintType)
struct FSlotInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FName Id = NAME_None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 Count;
};