#pragma once
#include "ITexture.h"

class Texturemanager : public ITexture {
    public:
        SDL_Texture* loadTexture(SDL_Renderer* renderer, const char* texture);
    private:
        SDL_Texture* tex;
};