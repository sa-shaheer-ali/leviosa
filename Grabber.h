// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEVIOSA_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void PressGrab();
	void ReleaseGrab();
	class APawn* pawn;
	class UPhysicsHandleComponent* PhysicsHandle;

	void PhysicsHandleComponent( class UPhysicsHandleComponent* PhysicsHandle);
	
	float value;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh, meta = (AllowPrivateAccess = "true"))
	float maxvalue;

	bool bHasGrabbed=false;

	bool bHasStartedGrab=false;
	//class IPickableInterface* interface;
	class IPickableInterface* interface;
	class AActor* actor;
};
