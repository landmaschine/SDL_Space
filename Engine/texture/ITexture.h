#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../renderer/renderer.h"

class ITexture {
    virtual SDL_Texture* loadTexture(SDL_Renderer* renderer,const char* texture) = 0;
};