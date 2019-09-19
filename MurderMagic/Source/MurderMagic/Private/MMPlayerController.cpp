// Fill out your copyright notice in the Description page of Project Settings.


#include "MMPlayerController.h"
#include "Templates.h"
#include "GameFramework/Character.h"

AMMPlayerController::AMMPlayerController()
{
}

void AMMPlayerController::BeginPlay()
{
	spellManager = (ASpellManager *)GetWorld()->SpawnActor(ASpellManager::StaticClass());
}

void AMMPlayerController::PlayerTick(float deltaTime)
{
	Super::PlayerTick(deltaTime);
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

}

void AMMPlayerController::ExitGame()
{
	ConsoleCommand("quit");
}

void AMMPlayerController::FireLSpell()
{
	FRotator direction = GetPawn()->GetActorRotation();
	float rAngle = direction.Yaw;
	//spellManager->CastSpellL(GetPawn()->GetActorLocation(), rAngle);
}

void AMMPlayerController::FireRSpell()
{
	FRotator direction = GetPawn()->GetActorRotation();
	float rAngle = direction.Yaw;
	//spellManager->CastSpellR(GetPawn()->GetActorLocation(), rAngle);
}

void AMMPlayerController::LNextSpell()
{
	spellManager->NextSpellL();
}

void AMMPlayerController::RNextSpell()
{
	spellManager->NextSpellR();
}