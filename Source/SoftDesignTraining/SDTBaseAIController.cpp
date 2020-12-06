// Fill out your copyright notice in the Description page of Project Settings.

#include "SDTBaseAIController.h"
#include "SoftDesignTraining.h"
#include "Supervisor.h"

ASDTBaseAIController::ASDTBaseAIController(const FObjectInitializer& ObjectInitializer)
    :Super(ObjectInitializer)
{
    PrimaryActorTick.bCanEverTick = true;
    PrimaryActorTick.bStartWithTickEnabled = true;
    m_ReachedTarget = true;

   Supervisor* supervisor = Supervisor::GetInstance();
    if (supervisor)
    {
        supervisor->RegisterAgent(this);
    }

}

void ASDTBaseAIController::Tick(float deltaTime)
{
    Super::Tick(deltaTime);

// ANCIEN TICK
  /*  UpdatePlayerInteraction(deltaTime);

    if (m_ReachedTarget)
    {
        GoToBestTarget(deltaTime);
    }
    else
    {
        ShowNavigationPath();
    }*/
}

void ASDTBaseAIController::SupervisedTick(float deltaTime, int Id)
{
    UpdatePlayerInteraction(deltaTime);

    if (m_ReachedTarget)
    {
        GoToBestTarget(deltaTime);
    }
    else
    {
        ShowNavigationPath();
    }
}

