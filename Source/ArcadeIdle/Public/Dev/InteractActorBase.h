// Arcade Idle Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "InteractActorBase.generated.h"

class UBoxComponent;

UCLASS()
class ARCADEIDLE_API AInteractActorBase : public AActor, public IInteractable
{
    GENERATED_BODY()

public:
    AInteractActorBase();

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Collision")
    UBoxComponent* BoxCollision;

    virtual void BeginPlay() override;

public:
    UFUNCTION()
    virtual void Interact(bool IsInteract, AActor* OtherActor) override;
};
