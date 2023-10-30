// Arcade Idle Game. All Rights Reserved.

#include "Dev/PickUpBase.h"
#include "Character/AIGBaseCharacter.h"

APickUpBase::APickUpBase()
{
    PrimaryActorTick.bCanEverTick = true;

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
    StaticMesh->SetupAttachment(GetRootComponent());
    StaticMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    StaticMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

void APickUpBase::BeginPlay()
{
    Super::BeginPlay();
}

void APickUpBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APickUpBase::Interact(bool IsInteract, AActor* OtherActor)
{
    if (IsInteract)
    {
        UE_LOG(LogTemp, Warning, TEXT("Overlaped with %s"), *OtherActor->GetName());
        auto Character = Cast<AAIGBaseCharacter>(OtherActor);
        if(Character)
        {
            Character->OnGetPicUp(this);
        }
       Destroy();
    }
}
