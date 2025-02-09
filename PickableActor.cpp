// Fill out your copyright notice in the Description page of Project Settings.


#include "PickableActor.h"

// Sets default values
APickableActor::APickableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent=Mesh;


}

// Called when the game starts or when spawned
void APickableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickableActor::StartGrab_Implementation(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Grab started"));
}

void APickableActor::EndGrab_Implementation(){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Grab ended"));
}