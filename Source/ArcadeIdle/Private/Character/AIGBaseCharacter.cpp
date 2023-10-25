// Arcade Idle Game. All Rights Reserved.

#include "Character/AIGBaseCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

AAIGBaseCharacter::AAIGBaseCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    bUseControllerRotationYaw = false; // Rotate character to moving direction

    GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
    GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);

    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponetn");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;
    SpringArmComponent->SocketOffset = FVector(-300.0f, 0.0f, 600.0f);

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraCompontent");
    CameraComponent->SetupAttachment(SpringArmComponent);
    CameraComponent->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
}

void AAIGBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AAIGBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AAIGBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    APlayerController* PC = Cast<APlayerController>(GetController());
    if (!PC) return;

    PC->bShowMouseCursor = true;
    PC->DefaultMouseCursor = EMouseCursor::Default;

    UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());

    Subsystem->ClearAllMappings();
    Subsystem->AddMappingContext(CharacterMapping, 0);

    UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
    if (!Input) return;

    Input->BindAction(SetDestinationClickAction, ETriggerEvent::Started, this, &AAIGBaseCharacter::OnInputStarted);
    Input->BindAction(SetDestinationClickAction, ETriggerEvent::Triggered, this, &AAIGBaseCharacter::OnSetDestinationTriggered);
    Input->BindAction(SetDestinationClickAction, ETriggerEvent::Completed, this, &AAIGBaseCharacter::OnSetDestinationReleased);
    Input->BindAction(SetDestinationClickAction, ETriggerEvent::Canceled, this, &AAIGBaseCharacter::OnSetDestinationReleased);
}

void AAIGBaseCharacter::OnInputStarted()
{
    APlayerController* PC = Cast<APlayerController>(GetController());
    if (!PC) return;

    PC->StopMovement();
}

void AAIGBaseCharacter::OnSetDestinationTriggered()
{
    // We flag that the input is being pressed
    FollowTime += GetWorld()->GetDeltaSeconds();

    // We look for the location in the world where the player has pressed the input
    FHitResult Hit;
    bool bHitSuccessful = false;

    APlayerController* PC = Cast<APlayerController>(GetController());
    if (!PC) return;

    bHitSuccessful = PC->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);

    // If we hit a surface, cache the location
    if (bHitSuccessful)
    {
        CachedDestination = Hit.Location;
    }

    // Move towards mouse pointer or touch
    FVector WorldDirection = (CachedDestination - GetActorLocation()).GetSafeNormal();
    AddMovementInput(WorldDirection, 1.0, false);
}

void AAIGBaseCharacter::OnSetDestinationReleased()
{
    // If it was a short press
    if (FollowTime <= ShortPressThreshold)
    {
        // We move there and spawn some particles
        APlayerController* PC = Cast<APlayerController>(GetController());
        if (!PC) return;

        UAIBlueprintHelperLibrary::SimpleMoveToLocation(PC, CachedDestination);
        UNiagaraFunctionLibrary::SpawnSystemAtLocation( //
            this,                                       //
            FXCursor,                                   //
            CachedDestination,                          //
            FRotator::ZeroRotator,                      //
            FVector::OneVector,                         //
            true,                                       //
            true,                                       //
            ENCPoolMethod::None,                        //
            true);
    }

    FollowTime = 0.f;
}
