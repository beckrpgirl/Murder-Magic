// Fill out your copyright notice in the Description page of Project Settings.


#include "MageBlast.h"

AMageBlast::AMageBlast()
{

}

AMageBlast::AMageBlast(ASpell* spell)
{
	burningHandsRef = spell;
}

void AMageBlast::BeginPlay()
{
	next = burningHandsRef;
}