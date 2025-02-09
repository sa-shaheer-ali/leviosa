// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "leviosaGameMode.generated.h"

UCLASS(minimalapi)
class AleviosaGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AleviosaGameMode();

protected:

void BeginPlay() override;

TArray<class ABucket*> Buckets;


UFUNCTION()
void OnBucketComplete(FString Message);

};



