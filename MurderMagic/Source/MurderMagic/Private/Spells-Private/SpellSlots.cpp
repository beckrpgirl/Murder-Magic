// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellSlots.h"
void USpellSlots::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	//Super::NativeTick(MyGeometry, DeltaTime);

	// Your code goes here
}

void USpellSlots::UpdateLeftSlotImage(UTexture2D* texture)
{
	SlotLeft->SetBrushFromTexture(texture);
}

void USpellSlots::UpdateRightSlotImage(UTexture2D* texture)
{
	SlotRight->SetBrushFromTexture(texture);
}
