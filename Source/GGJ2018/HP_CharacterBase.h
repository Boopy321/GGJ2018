// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "HP_CharacterBase.generated.h"

UCLASS()
class GGJ2018_API AHP_CharacterBase : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* CharMesh;

public:
	// Sets default values for this character's properties
	AHP_CharacterBase();

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
		void InitiateConversation(AHP_NPC* NPC);

	UFUNCTION(BlueprintCallable, Category = "Dialogue")
		void EndConversation();

	UFUNCTION(BlueprintImplementableEvent, Category = "ConversationThings")
		void ContinueConversation();

	UFUNCTION(BlueprintImplementableEvent, Category = "ConversationThings")
		void TaserNPC();

	UFUNCTION(BlueprintImplementableEvent, Category = "ConversationThings")
		void SetSwitch1();

	UFUNCTION(BlueprintImplementableEvent, Category = "ConversationThings")
		void SetSwitch2();

	UFUNCTION(BlueprintImplementableEvent, Category = "ConversationThings")
		void SetSwitch3();

	UFUNCTION(BlueprintImplementableEvent, Category = "ConversationThings")
		void InitConversation();

	UFUNCTION(BlueprintImplementableEvent, Category = "ConversationThings")
		void DeInitConversation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		float BaseLookUpRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Dialogue")
		class AHP_NPC* TalkingNPC;
	
protected:

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	* Called via input to turn at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to turn look up/down at a given rate.
	* @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	*/
	void LookUpAtRate(float Rate);

	void OnTaser();

	void Switch1();
	void Switch2();
	void Switch3();

	UPROPERTY(BlueprintReadOnly, Category = Movement)
		bool bMovementLocked = false;

	int32 SelectedMode = 1;
	
};
