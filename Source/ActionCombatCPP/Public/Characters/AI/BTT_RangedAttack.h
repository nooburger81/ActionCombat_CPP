// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_RangedAttack.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONCOMBATCPP_API UBTT_RangedAttack : public UBTTaskNode
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UAnimMontage* AnimMontage;

	double Threshold{ 0.9 };

	UPROPERTY(EditAnywhere)
	float MeleeRange{ 1250.0f };
	
public:
	virtual EBTNodeResult::Type ExecuteTask(
		UBehaviorTreeComponent& OwnerComp,
		uint8* NodeMemory
	) override;
};


