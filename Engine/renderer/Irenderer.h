#pragma once
class IGameObject;
#include <SDL2/SDL.h>
#include <iostream>

class Irenderer {
    public:
        virtual SDL_Renderer* renderer() = 0; 
};