// Fill out your copyright notice in the Description page of Project Settings.


#include "LightningStrikes.h"

ALightningStrikes::ALightningStrikes()
{

}

ALightningStrikes::ALightningStrikes(ASpell* spell)
{
	magiBoltRef = spell;
}

void ALightningStrikes::BeginPlay()
{
	next = magiBoltRef;
}
