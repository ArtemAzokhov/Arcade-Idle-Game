// Arcade Idle Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
    GENERATED_BODY()
};

class ARCADEIDLE_API IInteractable
{
    GENERATED_BODY()

public:
    UFUNCTION()
    virtual void Interact(bool IsInteract, AActor* OtherActor);
};
