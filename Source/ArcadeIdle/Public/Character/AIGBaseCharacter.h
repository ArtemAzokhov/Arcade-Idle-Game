// Arcade Idle Game. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIGBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;
class UNiagaraSystem;

UCLASS(Blueprintable)
class ARCADEIDLE_API AAIGBaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    AAIGBaseCharacter();

    void OnInputStarted();
    void OnSetDestinationTriggered();
    void OnSetDestinationReleased();

protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    float ShortPressThreshold = 0.5f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    UInputMappingContext* CharacterMapping;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    UInputAction* SetDestinationClickAction;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
    UNiagaraSystem* FXCursor;

    virtual void BeginPlay() override;

private:
    FVector CachedDestination = FVector::ZeroVector;
    float FollowTime = 0.0f; // For how long it has been pressed

    bool IsMovingForward = false;

public:
    virtual void Tick(float DeltaTime) override;

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
