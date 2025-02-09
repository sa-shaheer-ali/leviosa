// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PickableInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPickableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class LEVIOSA_API IPickableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
void StartGrab();
UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
void EndGrab();
};
