// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterOverview.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API UCharacterOverview : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize() override;
	
};
