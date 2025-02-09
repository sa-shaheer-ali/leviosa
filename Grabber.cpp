// Fill out your copyright notice in the Description page of Project Settings.


#include "Grabber.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

#include "PickableInterface.h"  // Replace with the actual file name

#include "DrawDebugHelpers.h"



// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	pawn=Cast<APawn>(GetOuter());
	
	
	
	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	

	

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
	
	
		if(!pawn) return;
		if(!PhysicsHandle) return;
		
	
		
		APlayerController* PlayerController=pawn->GetController<APlayerController>();
		if(!PlayerController) return ;
		FVector CameraLocation;
		FRotator CameraRotation;
		
		PlayerController->PlayerCameraManager->GetCameraViewPoint(CameraLocation,CameraRotation);
	
		FVector CameraForward=FRotationMatrix(CameraRotation).GetUnitAxis(EAxis::X);
		//DrawDebugSphere(GetWorld(),CameraLocation,20,12,FColor::Red,true);
		FVector CameraEnd=CameraLocation+CameraForward*value;
		//DrawDebugLine(GetWorld(),CameraLocation,CameraEnd,FColor::Green,true);
		PhysicsHandle->SetTargetLocation(CameraEnd);
	
	//	return;
	

	

	// ...
}

void UGrabber::PressGrab()
{
	
	if(!pawn) return;
	if(!PhysicsHandle)return;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Grab pressed"));
	APlayerController* PlayerController=pawn->GetController<APlayerController>();

	FVector CameraLocation;
	FRotator CameraRotation;

	if (PlayerController && PlayerController->PlayerCameraManager)
	{
		PlayerController->PlayerCameraManager->GetCameraViewPoint(CameraLocation, CameraRotation);
	}
	
	FVector CameraForward=FRotationMatrix(CameraRotation).GetUnitAxis(EAxis::X);
	FVector EndLocation=CameraLocation+CameraForward* 1000;
	//DrawDebugSphere(GetWorld(),CameraLocation,20,12,FColor::Red,true);
	//DrawDebugLine(GetWorld(),CameraLocation,CameraEnd,FColor::Green,true);
	FHitResult hit;

	if(GetWorld()->LineTraceSingleByChannel(hit, CameraLocation, EndLocation, ECC_GameTraceChannel1))
	{
		actor=hit.GetActor();
		interface=Cast<IPickableInterface>(actor);
	if( interface){
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Interface!!!!!!"));
		interface->Execute_StartGrab(actor);
		
		PhysicsHandle->GrabComponentAtLocationWithRotation(hit.GetComponent(),NAME_None,hit.Location,actor->GetActorRotation());	
		

		value=hit.Distance;   
		bHasGrabbed=true;
	}
	

}	


	
}


void UGrabber::ReleaseGrab()
{	
	if(!pawn) return;
	if(!actor) return;
	
	if(actor->GetClass()->ImplementsInterface(UPickableInterface::StaticClass()))
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Grab released"));
	interface->Execute_EndGrab(actor);
	PhysicsHandle->ReleaseComponent();
	bHasGrabbed = false;
	
}

void UGrabber::PhysicsHandleComponent( class UPhysicsHandleComponent* physicsHandle)
{
	this->PhysicsHandle=physicsHandle;

}
