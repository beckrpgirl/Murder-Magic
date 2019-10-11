// Fill out your copyright notice in the Description page of Project Settings.


#include "MMPlayerController.h"
#include "Templates.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"
#include "Trigger.h"
#include "MurderMagicCharacter.h"

AMMPlayerController::AMMPlayerController()
{
}

void AMMPlayerController::BeginPlay()
{
	spellManager = Cast<ASpellManager>(GetWorld()->SpawnActor(spellManagerBP));
	pawnRef = Cast<AMurderMagicCharacter>(GetPawn());
}

void AMMPlayerController::PlayerTick(float deltaTime)
{
	Super::PlayerTick(deltaTime);


	DeprojectMousePositionToWorld(mouseLocation, mouseDirection);

	FRotator currentCharacterRotation = pawnRef->GetActorRotation();
	FRotator targetRotation = mouseDirection.Rotation();

	FRotator newRotation = FRotator(currentCharacterRotation.Pitch, targetRotation.Yaw, currentCharacterRotation.Roll);
	pawnRef->SetActorRotation(newRotation);
}

void AMMPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &AMMPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMMPlayerController::MoveRight);

	//Binding the new player actions to their specific key presses set in UE4
	InputComponent->BindAction("QuitGame", IE_Pressed, this, &AMMPlayerController::ExitGame);
	InputComponent->BindAction("LeftAbility", IE_Pressed, this, &AMMPlayerController::FireLSpell);
	InputComponent->BindAction("RightAbility", IE_Pressed, this, &AMMPlayerController::FireRSpell);
	InputComponent->BindAction("ObjectInteract", IE_Pressed, this, &AMMPlayerController::ObjectInteract);
	InputComponent->BindAction("SwitchLeftAbility", IE_Pressed, this, &AMMPlayerController::LNextSpell);
	InputComponent->BindAction("SwitchRightAbility", IE_Pressed, this, &AMMPlayerController::RNextSpell);
}

void AMMPlayerController::MoveForward(float axisValue)
{
	GetPawn()->AddMovementInput(FVector(1, 0, 0), axisValue);
}

void AMMPlayerController::MoveRight(float axisValue)
{
	GetPawn()->AddMovementInput(FVector(0, 1, 0), axisValue);
}

void AMMPlayerController::ObjectInteract()
{

	//allows interraction with the triggers
	if (pawnRef && pawnRef->Triggers) {
		if (pawnRef->Triggers->CanActivate == true)
		{
			pawnRef->AddTriggersCollected();
			pawnRef->Triggers->OnInteract();
		}
		if (GEngine) {

			GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Orange, "Interacted with button");
		}
	}
}

void AMMPlayerController::ExitGame()
{
	ConsoleCommand("quit");
}

void AMMPlayerController::FireLSpell()
{
	if (pawnRef->GetCurrentMana() >= (spellManager->GetLeftSpell()->GetManaCost())) 
	{
		pawnRef->UseMana(spellManager->CastSpellL(GetPawn()->GetActorTransform()));
	}
	else if (pawnRef->GetCurrentMana() < (spellManager->GetLeftSpell()->GetManaCost())) 
	{
		return;
	}
}

void AMMPlayerController::FireRSpell()
{
	if ((pawnRef->GetCurrentMana()) >= (spellManager->GetRightSpell()->GetManaCost())) {

		pawnRef->UseMana(spellManager->CastSpellR(GetPawn()->GetActorTransform()));

	}
}

void AMMPlayerController::LNextSpell()
{
	spellManager->NextSpellL();
}

void AMMPlayerController::RNextSpell()
{
	spellManager->NextSpellR();
}

ASpellManager* AMMPlayerController::GetSpellManager()
{
	if (!spellManager)
		return nullptr;
	return spellManager;
}

UTexture2D* AMMPlayerController::GetLSTexture()
{
	UTexture2D* tempTexture = GetSpellManager()->GetLeftSpell()->SpellTexture;
	return tempTexture;
}

UTexture2D* AMMPlayerController::GetRSTexture()
{
	UTexture2D* tempTexture = GetSpellManager()->GetRightSpell()->SpellTexture;
	return tempTexture;
}
