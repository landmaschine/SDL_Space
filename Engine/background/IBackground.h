#pragma once
#include <SDL2/SDL.h>

class IBackground {
    public:
        virtual void draw(float cameraX, float cameraY) = 0;
        virtual SDL_FRect& rect() = 0;
};