// Fill out your copyright notice in the Description page of Project Settings.


#include "Bucket.h"
#include "Components/BoxComponent.h"

#include "Components/TextRenderComponent.h"

// Sets default values
ABucket::ABucket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxCollision=CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent=BoxCollision;
	TextRender=CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextRender"));
	TextRender->SetupAttachment(RootComponent);
	display();

	
}

// Called when the game starts or when spawned
void ABucket::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABucket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABucket::display(){
	FText Text= FText::FromString(FString::Printf(TEXT("%d/%d"),Amount,MaxAmount));
	TextRender->SetText(Text);
	if(Amount==MaxAmount){
		OnBucketComplete.Broadcast(Message);
	}

}

void ABucket::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Overlap"));
	Amount++;
	display();


}

void ABucket::OnEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("EndOverlap"));
	Amount--;
	display();
	
	
}


void ABucket::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this,&ABucket::OnBeginOverlap);
	BoxCollision->OnComponentEndOverlap.AddDynamic(this,&ABucket::OnEndOverlap);
}

