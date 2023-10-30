// Arcade Idle Game. All Rights Reserved.

#include "Dev/InteractActorBase.h"
#include "Components/BoxComponent.h"
#include "UI/AIGHUD.h"

AInteractActorBase::AInteractActorBase()
{
    PrimaryActorTick.bCanEverTick = false;

    BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
    BoxCollision->SetupAttachment(GetRootComponent());
    BoxCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    BoxCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
}

void AInteractActorBase::BeginPlay()
{
    Super::BeginPlay();
}

void AInteractActorBase::Interact(bool IsInteract, AActor* OtherActor)
{
    auto HUD = Cast<AAIGHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
    if (!HUD) return;

    if (IsInteract)
    {
        HUD->ShowPopUpMenu();
        UE_LOG(LogTemp, Warning, TEXT("HandleBeginOverlap"));
    }
    else
    {
        HUD->HidePopUpMenu();
        UE_LOG(LogTemp, Warning, TEXT("HandleEndOverlap"));
    }
}
