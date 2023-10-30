// Arcade Idle Game. All Rights Reserved.

#include "UI/AIGHUD.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"

void AAIGHUD::BeginPlay()
{
    Super::BeginPlay();

    ShowWidget(PlayerHUDWidgetClass);
    ShowWidget(AdviceWidgetClass);
}

void AAIGHUD::ShowWidget(TSubclassOf<UUserWidget> WidgetClass)
{
    auto Widget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
    if (Widget)
    {
        Widget->AddToViewport();
    }
}

void AAIGHUD::ShowPopUpMenu()
{
    PopUpWidget = CreateWidget<UUserWidget>(GetWorld(), PopUpWidgetClass);
    if (PopUpWidget)
    {
        PopUpWidget->AddToViewport();
    }
}

void AAIGHUD::HidePopUpMenu()
{
    UWidgetBlueprintLibrary::SetInputMode_GameOnly(GetOwningPawn()->GetLocalViewingPlayerController());
    UGameplayStatics::SetViewportMouseCaptureMode(GetWorld(), EMouseCaptureMode::CaptureDuringMouseDown);
    PopUpWidget->RemoveFromParent();
}
