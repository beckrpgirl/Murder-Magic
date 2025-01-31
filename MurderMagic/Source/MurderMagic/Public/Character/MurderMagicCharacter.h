// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameHUD.h"
#include "GameFramework/Character.h"
#include "Engine/DataTable.h"
#include "MurderMagicCharacter.generated.h"

class ACollectibleParent;
class ATrigger;
class ANPC;

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

	float Health;
	float MaxHealth;

	float Mana;
	float MaxMana;
	float ManaRegen;

	float Experience;
	float ExperienceToNextLevel;

	int TriggersCollected;
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlapComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Hit);

	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:

	AMurderMagicCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	UPROPERTY(EditAnywhere)
	UDataTable* DataTable;

	FDataTableStruct* Row;
	
	int currentAP;
	int CurrentPlayerLevel;
	int CurrentFloor;

	FTimerHandle AddMana_Handler;
	/*NO PUBLIC VARIABLES PLEASE!!!! STEVEN C*/
	bool AddHealth(float Points);

	void RegenMana();
	bool UseMana(float Points);
	bool AddMana(float Points);

	bool AddExperience(float Points);

	//Steve Approved
	UFUNCTION(BlueprintCallable, category = MMC)
	int GetCurrentPlayerLevel();

	float GetManaPercent();
	float GetHealthPercent();
	float GetExperiencePercent();
	float GetExperience();
	float GetMaxExperience();
	float GetCurrentMana();
	int GetTriggersCollected();
	void AddTriggersCollected();

	void PlayerLevelup();
	void SetPlayerStats();

	void SubtractAP();
	int GetTotalAP();

	ACollectibleParent* Collectibles;
	ATrigger* Triggers;


	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

};

