#pragma once
#include "EngineUtils.h"

template<typename T>
void FindAllActors(UWorld* World, TArray<T*>& Out)
{
	for (TActorIterator<T> It(World); It; ++It)
	{
		Out.Add(*It);
	}
}

template<typename T>
void FindAllObjects(UWorld* World, TArray<T*>& Out)
{
	for (TObjectIterator<T> It(World); It; ++It)
	{
		Out.Add(*It);
	}
}