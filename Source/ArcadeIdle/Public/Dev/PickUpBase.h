// Arcade Idle Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "PickUpBase.generated.h"

UCLASS()
class ARCADEIDLE_API APickUpBase : public AActor, public IInteractable
{
    GENERATED_BODY()

public:
    APickUpBase();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "PickUp")
    UStaticMeshComponent* StaticMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PickUp")
    FName PickUpName = FName(TEXT("Enter Pickup name here!"));

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PickUp")
    float PickUpValue = 1.0f;

public:
    virtual void Tick(float DeltaTime) override;

    UFUNCTION()
    virtual void Interact(bool IsInteract, AActor* OtherActor) override;

    UFUNCTION()
    float GetPickUpValue() { return PickUpValue; };

    UFUNCTION()
    FName GetPickUpName() { return PickUpName; };
};
