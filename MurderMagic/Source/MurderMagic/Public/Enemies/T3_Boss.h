// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPC.h"
#include "T3_Boss.generated.h"


class ABossDoor;
/**
 * 
 */
UCLASS()
class MURDERMAGIC_API AT3_Boss : public ANPC
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere)
	ABossDoor* door;
	

public:

	virtual void ReduceHealth(int DamageAmount) override;

};
