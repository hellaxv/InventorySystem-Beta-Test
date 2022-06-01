// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameData/ItemInfo.h"
#include "GameFramework/GameModeBase.h"
#include "InventorySystemGameMode.generated.h"

UCLASS(minimalapi)
class AInventorySystemGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AInventorySystemGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UDataTable* ItemsData;
	
	UFUNCTION(BlueprintCallable)
	FItemInfo GetItemInfo(FName ItemID){return *ItemsData->FindRow<FItemInfo>(ItemID, "");};
	
};



