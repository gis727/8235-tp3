// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SDTBaseAIController.h"
#include "TickerActor.h"

/**
 *
 */
class SOFTDESIGNTRAINING_API Supervisor
{
public:
	Supervisor();
	~Supervisor();

	void Reset();

	void RegisterAgent(ASDTBaseAIController* AiAgent);
	void Supervise(float deltaTime);
	static Supervisor* GetInstance();
	void RegisterTicker(ATickerActor* Tickeractor);

private:

	static Supervisor* Instance;

	TArray<ASDTBaseAIController*> Agents;

	ATickerActor* TickerActor;

	int AgentNumber = 0;
	int Counter = 0;
	double Budget = 0.02;
	double TimeElapsed = 0;
	double Start = 0;
	double End = 0;

};
