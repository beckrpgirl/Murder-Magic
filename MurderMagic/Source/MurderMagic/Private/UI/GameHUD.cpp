// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"
#include "UserWidget.h"


AGameHUD::AGameHUD()
{



}

void AGameHUD::BeginPlay()
{

	Super::BeginPlay();
	MyWorld = GetWorld();
	CurrentMapName = MyWorld->GetMapName();



	if (hudWidgetClass)
	{
		if (CurrentMapName == "UEDPIE_0_MainMenu")
		{
			hudWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), hudWidgetMMClass);
			hudWidget->AddToViewport();
		}
		if (CurrentMapName == "UEDPIE_0_WinScreen")
		{
			hudWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), hudWidgetWSClass);
			hudWidget->AddToViewport();
		}
		if (CurrentMapName != "UEDPIE_0_MainMenu" && CurrentMapName != "UEDPIE_0_WinScreen")
		{
			hudWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), hudWidgetClass);
			hudWidget->AddToViewport();
		}
		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "Widget has been loaded");
	}

}

FString AGameHUD::GetCurrentMapName()
{
	return CurrentMapName;
}
