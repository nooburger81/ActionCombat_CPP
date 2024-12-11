// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerActionsComponent.h"

#include <ThirdParty/ShaderConductor/ShaderConductor/External/DirectXShaderCompiler/include/dxc/DXIL/DxilConstants.h>

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interfaces/PlayerInterface.h"

// Sets default values for this component's properties
UPlayerActionsComponent::UPlayerActionsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerActionsComponent::BeginPlay()
{
	Super::BeginPlay();

	CharacterRef = GetOwner<ACharacter>();
	MovementComp = CharacterRef->GetCharacterMovement();

	if (CharacterRef->Implements<UPlayerInterface>()) { return; }

	IPlayerRef = Cast<IPlayerInterface>(CharacterRef);
	
}


// Called every frame
void UPlayerActionsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerActionsComponent::Sprint()
{
	if (!IPlayerRef->HasEnoughStamina(SprintCost)) { return; }

	MovementComp->MaxWalkSpeed = SprintSpeed;
}

void UPlayerActionsComponent::Walk()
{
	MovementComp->MaxWalkSpeed = WalkSpeed;
}

