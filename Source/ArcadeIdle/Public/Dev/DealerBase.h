// Arcade Idle Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "DealerBase.generated.h"

class UBoxComponent;

UCLASS()
class ARCADEIDLE_API ADealerBase : public AActor, public IInteractable
{
    GENERATED_BODY()

public:
    ADealerBase();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dealer")
    UStaticMeshComponent* StaticMesh;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Dealer")
    UBoxComponent* ColissionComponent;

public:
    UFUNCTION()
    virtual void Interact(bool IsInteract, AActor* OtherActor) override;
};
