// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellEffect.h"
#include "ConstructorHelpers.h"

// Sets default values for this component's properties
USpellEffect::USpellEffect()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	PSC = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	PSC->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);
	collisionShape = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collision"));
	collisionShape->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);
	// ...

	active = false;
}

void USpellEffect::Init(FTransform Start, FTransform End, float maxTime)
{
	basePoint = GetComponentTransform();
	SetWorldTransform(Start);
	startPoint = Start;
	endPoint = End;
	maxLife = maxTime;
	lifeTime = 0;
	active = true;
}

void USpellEffect::Update(float deltaSeconds)
{
	lifeTime += deltaSeconds;
	if (lifeTime < maxLife)
	{ 
		FTransform newTrans;
		newTrans.SetLocation(CalcNewVector(startPoint.GetLocation(), endPoint.GetLocation(), lifeTime / maxLife));
		newTrans.SetRotation(CalcNewVector(startPoint.GetRotation().Vector(), endPoint.GetRotation().Vector(), lifeTime / maxLife).ToOrientationQuat());
		newTrans.SetScale3D(CalcNewVector(startPoint.GetScale3D(), endPoint.GetScale3D(), lifeTime / maxLife));

		SetWorldTransform(newTrans);
	}
	else
	{
		active = false;
		SetWorldTransform(basePoint);
	}
}

FVector USpellEffect::CalcNewVector(FVector start, FVector end, float progress)
{
	FVector result;
	result.X = start.X + ((end.X - start.X) * progress);
	result.Y = start.Y + ((end.Y - start.Y) * progress);
	result.Z = start.Z + ((end.Z - start.Z) * progress);
	return result;
}


// Called when the game starts
void USpellEffect::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpellEffect::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (active)
	{
		Update(DeltaTime);
	}
}

UParticleSystemComponent* USpellEffect::GetPSC()
{
	return PSC;
}

UStaticMeshComponent* USpellEffect::GetCollisionShape()
{
	return collisionShape;
}

bool USpellEffect::Activated()
{
	return active;
}