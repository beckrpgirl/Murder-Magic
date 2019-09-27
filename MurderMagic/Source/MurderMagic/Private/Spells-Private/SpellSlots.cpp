// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellSlots.h"
#include "MMPlayerController.h"
#include "Spell.h"
#include "SpellManager.h"
void USpellSlots::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	//Super::NativeTick(MyGeometry, DeltaTime);

	// Your code goes here
}

void USpellSlots::UpdateLeftSlotImage(UTexture2D* texture)
{
	SlotLeft->SetBrushFromTexture(texture);
	textureLS = texture;
}

void USpellSlots::UpdateRightSlotImage(UTexture2D* texture)
{
	SlotRight->SetBrushFromTexture(texture);
}

//create a second BlueprintPure function to update the rightSlot(also rename this function to match what its doing)
FSlateBrush USpellSlots::updateImage()
{
	AMMPlayerController* pc = Cast<AMMPlayerController>(GetOwningPlayerPawn()->Controller);
	//Create a function in PlayerController that returns the Texture of the spell. so we can remove Spell.h and SpellManager.h from our includes above
	/*Remove textureLS from the header of this class*/textureLS = pc->GetSpellManager()->GetLeftSpell()->SpellTexture;


	//textureLS = 

	FSlateBrush SB;
	SB.SetResourceObject(textureLS);

	return SB;
}