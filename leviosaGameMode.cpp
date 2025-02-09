// Copyright Epic Games, Inc. All Rights Reserved.

#include "leviosaGameMode.h"
#include "leviosaCharacter.h"
#include "Bucket.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AleviosaGameMode::AleviosaGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AleviosaGameMode::BeginPlay()
{
	Super::BeginPlay();

	UWorld * World = GetWorld();
	if(!World) return;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(World, ABucket::StaticClass(), FoundActors);

	for(AActor * FoundActor : FoundActors){

		ABucket *Bucket=Cast<ABucket>(FoundActor);
		if(Bucket){
			Buckets.Add(Bucket);
			Bucket->OnBucketComplete.AddDynamic(this, &AleviosaGameMode::OnBucketComplete);

		}

	}

}

void AleviosaGameMode::OnBucketComplete(FString Message){
	GEngine->AddOnScreenDebugMessage(-1,2,FColor::Green,FString::Printf(TEXT("Bucket Completed: %s"),*Message));

}