// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TickerActor.generated.h"

UCLASS()
class SOFTDESIGNTRAINING_API ATickerActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATickerActor();

	virtual void BeginDestroy() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void BeginTicking();

	bool TicTac = false;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;




};
