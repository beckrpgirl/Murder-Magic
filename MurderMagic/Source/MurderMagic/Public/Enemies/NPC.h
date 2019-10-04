// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MMPlayerController.h"
#include "NPCAIController.h"
#include "Collectible_EXP.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"
#include "NPC.generated.h"

UCLASS()
class MURDERMAGIC_API ANPC : public ACharacter
{
private:

	GENERATED_BODY()

	UPROPERTY(VisibleDefaultsOnly)
	USphereComponent* CollisionSphere;
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Stats")
	float MovementSpeed;
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Stats")
	float MaxHealth;
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Stats")
	float Health;
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Stats")
	float Damage;
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Stats")
	float AttackSpeed;
	UPROPERTY(EditDefaultsOnly, Category = "Enemy Stats")
	int EXPWorth;
	UPROPERTY(EditDefaultsOnly, Category = "Enemy pickup")
	UClass* CollectiblePickups;


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "Enemy Stats")
	UWidgetComponent *hpBar;

	// Sets default values for this character's properties
	ANPC(const FObjectInitializer& OI);

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetHealth(float hp);

	float GetHealthPercent();

	UFUNCTION(BlueprintCallable)
	virtual void ReduceHealth(int DamageAmount);
	void SpawnCollectible(int SpawnAmount);

	float GetDamage();
	int GetXPValue();

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	class UBehaviorTree* BehaviorTree;

};
