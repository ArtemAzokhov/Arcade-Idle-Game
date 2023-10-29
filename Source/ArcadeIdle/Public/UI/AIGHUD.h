// Arcade Idle Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AIGHUD.generated.h"

UCLASS()
class ARCADEIDLE_API AAIGHUD : public AHUD
{
    GENERATED_BODY()

public:
    void ShowWidget(TSubclassOf<UUserWidget> WidgetClass);

    void ShowPopUpMenu();
    void HidePopUpMenu();

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PopUpWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> AdviceWidgetClass;

    virtual void BeginPlay() override;

    private:
    UUserWidget* PopUpWidget;
};
