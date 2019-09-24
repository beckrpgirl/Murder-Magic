// Fill out your copyright notice in the Description page of Project Settings.
//Runtime\UMG\Public\Components\Image.h
#pragma once
#include "Runtime/UMG/Public/Components/Image.h"
#include "Styling/SlateBrush.h"
#include "GameHUD.h"
#include "MurderMagicCharacter.h"
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SpellSlots.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API USpellSlots : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* SlotLeft;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* SlotRight;



};
