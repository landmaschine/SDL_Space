#pragma once
#include "../player/player.h"
#include "../math/vec2D.h"
#include "../window/window.h"

class ICamera {
    public:
        virtual void easing(IPlayer &player, Iwindow& win, float modifier) = 0;
        virtual SDL_FRect& rect() = 0;
};