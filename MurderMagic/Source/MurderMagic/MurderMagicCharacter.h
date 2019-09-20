// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LevelManager.h"
#include "Engine/DataTable.h"
#include "MurderMagicCharacter.generated.h"

class ACollectibleParent;
class ATrigger;

USTRUCT(Blueprintable)
struct FDataTableStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Levelup")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Levelup")
	float MaxMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Levelup")
	float ExperienceToNextLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Levelup")
	int AbilityPoint;

};

UCLASS(config=Game)
class AMurderMagicCharacter : public ACharacter
{
private:

	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, Category = "Trigger")
		class UCapsuleComponent* TriggerCapsule;

public:

	AMurderMagicCharacter();

	ALevelManager *CurrentLevelManager;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(EditAnywhere)
	UDataTable* DataTable;

	FDataTableStruct* Row;

	virtual void BeginPlay() override;

	float Health;
	float MaxHealth;

	float Mana;
	float MaxMana;
	float ManaRegen;

	float Experience;
	float ExperienceToNextLevel;

	int CurrentPlayerLevel;
	int CurrentFloor;

	FTimerHandle AddMana_Handler;

	bool AddHealth(float Points);

	void RegenMana();
	bool UseMana(float Points);
	bool AddMana(float Points);

	bool AddExperience(float Points);

	float GetManaPercent();
	float GetHealthPercent();
	float GetExperiencePercent();

	void PlayerLevelup();
	void PlayerStats();

	ACollectibleParent* Collectibles;
	ATrigger* Triggers;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	void ObjectInteract();

	void CheckPointRespond();

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

