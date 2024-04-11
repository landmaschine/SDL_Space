#pragma once
#include <SDL2/SDL.h>

class IBackground {
    public:
        virtual void draw() = 0;
        virtual SDL_FRect& rect() = 0;
};