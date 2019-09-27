// Fill out your copyright notice in the Description page of Project Settings.


#include "WindSurge.h"

AWindSurge::AWindSurge()
{

}

AWindSurge::AWindSurge(ASpell* spell)
{
	mageBlastRef = spell;
}

void AWindSurge::BeginPlay()
{
	next = mageBlastRef;
}