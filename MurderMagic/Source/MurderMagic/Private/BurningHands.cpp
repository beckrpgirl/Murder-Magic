// Fill out your copyright notice in the Description page of Project Settings.


#include "BurningHands.h"

ABurningHands::ABurningHands()
{

}

ABurningHands::ABurningHands(ASpell* spell)
{
	lightningStrikesRef = spell;
}

void ABurningHands::BeginPlay()
{
	next = lightningStrikesRef;
}
