// Fill out your copyright notice in the Description page of Project Settings.

#include "GGJ2018.h"
#include "HP_NPC.h"


// Sets default values
AHP_NPC::AHP_NPC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CharMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharMesh"));
}

// Called when the game starts or when spawned
void AHP_NPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHP_NPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

