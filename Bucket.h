// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bucket.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBucketComplete, FString, Message);
UCLASS()
class LEVIOSA_API ABucket : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABucket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bucket")
	int32 Amount=0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bucket")
	int32 MaxAmount=2;

	private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* BoxCollision;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))

	class UTextRenderComponent* TextRender;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	void PostInitializeComponents();
	public:
	UPROPERTY(BlueprintAssignable,meta=(AllowPrivateAccess="true"))
	FOnBucketComplete OnBucketComplete;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Message="Default Message";


	void display();
};	
