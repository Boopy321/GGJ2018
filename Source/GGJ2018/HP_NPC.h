// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "HP_NPC.generated.h"

UCLASS()
class GGJ2018_API AHP_NPC : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* CharMesh;

public:	
	// Sets default values for this actor's properties
	AHP_NPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NPC")
		int32 CharacterID = 0;

	UPROPERTY(BlueprintReadWrite, Category = "NPC")
		int32 DialogueKey = 0;
	
};
