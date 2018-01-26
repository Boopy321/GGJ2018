// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "HP_GameInstance.generated.h"

USTRUCT(BlueprintType)
struct FDialogue : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:

	FDialogue()
		: Dialogue()
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
		FText Dialogue;
};

/**
 * 
 */
UCLASS()
class GGJ2018_API UHP_GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	
	
};
