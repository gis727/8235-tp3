// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_TargetPlayer.h"
#include "../SDTAIController.h"
#include "../SoftDesignTrainingGameMode.h"

EBTNodeResult::Type UBTTask_TargetPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ASDTAIController* aiController = Cast<ASDTAIController>(OwnerComp.GetAIOwner()))
	{
		const ASDTAIController::PlayerInteractionBehavior previousBehavior = aiController->m_PlayerInteractionBehavior;
		const ASDTAIController::PlayerInteractionBehavior newBehavior = ASDTAIController::PlayerInteractionBehavior_Chase;

		if (previousBehavior != newBehavior)
		{
			aiController->m_PlayerInteractionBehavior = newBehavior;
			aiController->AIStateInterrupted();

			if (ASoftDesignTrainingGameMode* gameMode = Cast<ASoftDesignTrainingGameMode>(aiController->GetWorld()->GetAuthGameMode()))
			{
				gameMode->squadManager.AddPawn(aiController);
			}
		}
		return EBTNodeResult::Succeeded;
	}
	return EBTNodeResult::Failed;
}
