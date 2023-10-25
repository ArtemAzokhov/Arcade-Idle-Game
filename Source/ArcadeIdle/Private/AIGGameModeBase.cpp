// Arcade Idle Game. All Rights Reserved.


#include "AIGGameModeBase.h"
#include "UI/AIGHUD.h"
#include "Character/AIGBaseCharacter.h"
#include "Character/AIGPlayerController.h"

AAIGGameModeBase::AAIGGameModeBase()
{
    HUDClass = AAIGHUD::StaticClass();
    DefaultPawnClass = AAIGBaseCharacter::StaticClass();
    PlayerControllerClass = AAIGPlayerController::StaticClass();
}
