// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "GGJ2018HUD.generated.h"

UCLASS()
class AGGJ2018HUD : public AHUD
{
	GENERATED_BODY()

public:
	AGGJ2018HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

