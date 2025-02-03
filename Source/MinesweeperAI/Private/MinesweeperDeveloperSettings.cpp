// Fill out your copyright notice in the Description page of Project Settings.


#include "MinesweeperDeveloperSettings.h"

void UMinesweeperDeveloperSettings::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	UObject::PostEditChangeProperty(PropertyChangedEvent);
	FName PropertyName = PropertyChangedEvent.GetPropertyName();
	if (PropertyName == GET_MEMBER_NAME_CHECKED(UMinesweeperDeveloperSettings, OpenAi_API_Key))
	{
		UE_LOG(LogTemp, Log, TEXT("OpenAIAPIKey has been updated: %s"), *OpenAi_API_Key);
		SaveConfig();
		GConfig->Flush(false, GGameIni);
	}
}
