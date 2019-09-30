// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MMPlayerController.h"
#include "NPCAIController.h"
#include "Collectible_EXP.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "NPC.generated.h"

UCLASS()
class MURDERMAGIC_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC(const FObjectInitializer& OI);

	UPROPERTY(VisibleDefaultsOnly)
	USphereComponent* CollisionSphere;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	class UBehaviorTree* BehaviorTree;
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
	UClass* EXPPickup;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float GetHealthPercent();
	virtual bool TakeDamage(int DamageAmount);
	void SpawnEXP(int SpawnAmount);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
