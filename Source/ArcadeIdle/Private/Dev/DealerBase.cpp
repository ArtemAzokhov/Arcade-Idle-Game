// Arcade Idle Game. All Rights Reserved.

#include "Dev/DealerBase.h"
#include "Components/BoxComponent.h"
#include "Character/AIGBaseCharacter.h"

ADealerBase::ADealerBase()
{
    PrimaryActorTick.bCanEverTick = false;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");

    ColissionComponent = CreateDefaultSubobject<UBoxComponent>("ColissionComponent");
    ColissionComponent->SetupAttachment(StaticMesh);
    ColissionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    ColissionComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

void ADealerBase::BeginPlay()
{
    Super::BeginPlay();
}

void ADealerBase::Interact(bool IsInteract, AActor* OtherActor)
{
    if (IsInteract)
    {
        UE_LOG(LogTemp, Warning, TEXT("Overlaped with %s"), *OtherActor->GetName());
        auto Character = Cast<AAIGBaseCharacter>(OtherActor);
        if (Character)
        {
            UE_LOG(LogTemp, Warning, TEXT("Resource before: %i"), Character->ResourceAmount);
            Character->AddResource();
            UE_LOG(LogTemp, Warning, TEXT("Resource after: %i"), Character->ResourceAmount);

            UE_LOG(LogTemp, Warning, TEXT("Inventory before: %i"), Character->InventoryAmount);
            Character->DecreaseInventory();
            UE_LOG(LogTemp, Warning, TEXT("Inventory after: %i"), Character->InventoryAmount);
        }
    }
}
