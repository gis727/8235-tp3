// Fill out your copyright notice in the Description page of Project Settings.


#include "TickerActor.h"
#include "Supervisor.h"

// Sets default values
ATickerActor::ATickerActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Supervisor* supervisor = Supervisor::GetInstance();
	if (supervisor)
	{
		supervisor->RegisterTicker(this);
	}

}


void ATickerActor::BeginTicking()
{
	TicTac = true;
	UE_LOG(LogTemp, Warning, TEXT("ticker actor ticking"));
}

// Called when the game starts or when spawned
void ATickerActor::BeginPlay()
{
	Super::BeginPlay();


}

void ATickerActor::BeginDestroy()
{
	Super::BeginDestroy();

	Supervisor* supervisor = Supervisor::GetInstance();
	if (supervisor)
	{
		supervisor->Reset();
	}
}

// Called every frame
void ATickerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("tic tac"));
	if (TicTac)
	{
		Supervisor* supervisor = Supervisor::GetInstance();
		if (supervisor)
		{
			supervisor->Supervise(DeltaTime);
		}
	}

}

