// Fill out your copyright notice in the Description page of Project Settings.

#include "GGJ2018.h"
#include "HP_CharacterBase.h"
#include "HP_NPC.h"


// Sets default values
AHP_CharacterBase::AHP_CharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// camera
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	//mesh
	CharMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharMesh"));
	CharMesh->SetOnlyOwnerSee(true);
	CharMesh->SetupAttachment(FirstPersonCameraComponent);
	CharMesh->bCastDynamicShadow = false;
	CharMesh->CastShadow = false;
	CharMesh->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	CharMesh->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);

	TalkingNPC = nullptr;
}

// Called when the game starts or when spawned
void AHP_CharacterBase::BeginPlay()
{
	Super::BeginPlay();

	//CharMesh->SetHiddenInGame(false, true);
	
}

// Called every frame
void AHP_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHP_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	check(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AHP_CharacterBase::OnTaser);

	PlayerInputComponent->BindAction("1", IE_Pressed, this, &AHP_CharacterBase::Switch1);
	PlayerInputComponent->BindAction("2", IE_Pressed, this, &AHP_CharacterBase::Switch2);
	PlayerInputComponent->BindAction("3", IE_Pressed, this, &AHP_CharacterBase::Switch3);

	PlayerInputComponent->BindAxis("MoveForward", this, &AHP_CharacterBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AHP_CharacterBase::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AHP_CharacterBase::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AHP_CharacterBase::LookUpAtRate);
}

void AHP_CharacterBase::MoveForward(float Value)
{
	if (Value != 0.0f && !bMovementLocked)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AHP_CharacterBase::MoveRight(float Value)
{
	if (Value != 0.0f && !bMovementLocked)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AHP_CharacterBase::TurnAtRate(float Rate)
{
		// calculate delta for this frame from the rate information
		AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AHP_CharacterBase::LookUpAtRate(float Rate)
{
		// calculate delta for this frame from the rate information
		AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AHP_CharacterBase::InitiateConversation(AHP_NPC* NPC)
{
	TalkingNPC = NPC;
	bMovementLocked = true;

	InitConversation();
}

void AHP_CharacterBase::EndConversation()
{
	TalkingNPC = nullptr;
	bMovementLocked = false;

	DeInitConversation();
}

void AHP_CharacterBase::OnTaser()
{
	if (SelectedMode < 3)
	{
		//continue convo
		ContinueConversation();

	}
	else
	{
		//end convo 
		TaserNPC();
	}
}

void AHP_CharacterBase::Switch1()
{
	SelectedMode = 1;

	SetSwitch1();
}

void AHP_CharacterBase::Switch2()
{
	SelectedMode = 2;

	SetSwitch2();
}

void AHP_CharacterBase::Switch3()
{
	SelectedMode = 3;

	SetSwitch3();
}