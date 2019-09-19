// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell.h"

ASpell::ASpell()
{
	spellCD = 0;
	sinceCast = 0;
	range = 0;
	baseDMG = 0;
}

void ASpell::Cast(FVector start, float angle)
{
	FVector destination;
	destination.X = start.X + (FMath::Cos(angle) * range);
	destination.Y = start.Y + (FMath::Sin(angle) * range);
	destination.Z = start.Z;

}