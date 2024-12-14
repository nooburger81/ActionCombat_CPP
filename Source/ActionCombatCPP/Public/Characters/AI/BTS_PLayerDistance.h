// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BTS_PLayerDistance.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONCOMBATCPP_API UBTS_PLayerDistance : public UBTService
{
	GENERATED_BODY()

	protected:
	virtual void TickNode (
		UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory,
		float DeltaSeconds
		) override;
};