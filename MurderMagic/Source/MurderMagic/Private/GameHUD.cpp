// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"


AGameHUD::AGameHUD() {



}

void AGameHUD::BeginPlay()
{

	Super::BeginPlay();

	if (hudWidgetClass)
	{
		////hudWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), hudWidgetClass);
		////hudWidget->AddToViewport();
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 2, FColor::Purple, "Widget has been loaded");
	}

}
