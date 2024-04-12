#pragma once
class I_input;
class IPlayer;
#include "../player/player.h"
#include "../input/input.h"

class IMovement {
    public:
        virtual void playerPosUpdate(IPlayer& player, I_input& input, float dt) = 0;
        virtual void playerRotUpdate(IPlayer& player, I_input& input, float dt) = 0;
};