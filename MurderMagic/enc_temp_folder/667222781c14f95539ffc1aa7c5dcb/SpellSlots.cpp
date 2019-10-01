// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellSlots.h"
#include "MMPlayerController.h"
void USpellSlots::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
}

FSlateBrush USpellSlots::UpdateLeftSlotImage()
{
	AMMPlayerController* pc = Cast<AMMPlayerController>(GetOwningPlayerPawn()->Controller); 

	FSlateBrush SB;
	SB.SetResourceObject(pc->GetLSTexture());

	return SB;
}

FSlateBrush USpellSlots::UpdateRightSlotImage()
{
	AMMPlayerController* pc = Cast<AMMPlayerController>(GetOwningPlayerPawn()->Controller); 

	FSlateBrush SB;
	SB.SetResourceObject(pc->GetRSTexture());

	return SB;
}
