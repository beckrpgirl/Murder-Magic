// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"
#include "UserWidget.h"


AGameHUD::AGameHUD() {



}

void AGameHUD::BeginPlay()
{

	Super::BeginPlay();

	UWorld* MyWorld = GetWorld();
	FString CurrentMapName = MyWorld->GetMapName();



	if (hudWidgetClass)
	{
		if (CurrentMapName == "UEDPIE_0_MainMenu")
		{
			hudWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), hudWidgetMMClass);
			hudWidget->AddToViewport();
		}
		else
		{
			hudWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), hudWidgetClass);
			hudWidget->AddToViewport();
		}
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "Widget has been loaded");
	}

}

FString AGameHUD::GetCurrentMapName()
{
	UWorld* MyWorld = GetWorld();
	FString CurrentMapName = MyWorld->GetMapName();

	return CurrentMapName;
}
