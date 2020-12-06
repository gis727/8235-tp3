// Fill out your copyright notice in the Description page of Project Settings.


#include "Supervisor.h"


Supervisor* Supervisor::Instance;


Supervisor::Supervisor()
{
}

Supervisor::~Supervisor()
{
}

void Supervisor::Reset()
{
	delete Instance;
	Instance = nullptr;
}

Supervisor* Supervisor::GetInstance()
{
	if (!Instance)
	{
		Instance = new Supervisor();
	}

	return Instance;
}

void Supervisor::RegisterTicker(ATickerActor* actor)
{
	TickerActor = actor;
}

void Supervisor::RegisterAgent(ASDTBaseAIController* AiAgent)
{

	int index = Agents.AddUnique(AiAgent);
	
	if (index >= 0)
	{
		AgentNumber++;
	}

	// Ne lance qu'une fois un nombre consequent d'agent present
	if (AgentNumber == 50 && TickerActor)
	{
		TickerActor->BeginTicking();
	}
}

void Supervisor::Supervise(float deltaTime)
{
	while (TimeElapsed < Budget)
	{
		Start = FPlatformTime::Seconds();
		Agents[Counter]->SupervisedTick(deltaTime, Counter);
		End = FPlatformTime::Seconds();
		TimeElapsed = TimeElapsed + (End - Start);

		if (Counter == AgentNumber - 1)
		{
			Counter = 0;
		}
		else
		{
			Counter++;
		}
	}

	TimeElapsed = 0;
}