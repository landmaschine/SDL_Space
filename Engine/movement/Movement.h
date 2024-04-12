#pragma once
#include "IMovement.h"

class Movement : public IMovement {
    public:
        void playerPosUpdate(IPlayer& player, I_input& input, float dt) override;
        void playerRotUpdate(IPlayer& player, I_input& input, float dt) override;
    private:
        const float deadzone = 25.f;
        const float speed = 1000;
};