// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MurderMagicCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpellManager.h"
#include "MMPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MURDERMAGIC_API AMMPlayerController : public APlayerController
{
private:

	GENERATED_BODY()

	ASpellManager* spellManager;

protected:

	virtual void BeginPlay() override;

	// Begin PlayerController interface
	virtual void PlayerTick(float deltaTime) override;

	virtual void SetupInputComponent() override;
	
public:

	AMMPlayerController();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ASpellManager> spellManagerBP;
	UFUNCTION()
	void MoveForward(float axisValue);
	UFUNCTION()
	void MoveRight(float axisValue);

	void ObjectInteract();

	void ExitGame();

	void FireLSpell();
	void FireRSpell();
	void LNextSpell();
	void RNextSpell();

	AMurderMagicCharacter* pawnRef;

	ASpellManager* GetSpellManager();
};
