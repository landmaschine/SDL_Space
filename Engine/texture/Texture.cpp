#include "Texture.h"

SDL_Texture* Texturemanager::loadTexture(SDL_Renderer* renderer,const char* texture) {
    if(texture == nullptr) {
        std::cout << "No Texture given!\n";
    }
    tex = IMG_LoadTexture(renderer, texture);

    if(tex == nullptr) {
        std::cout << "Loading texture failed" << std::endl;
    }

    return tex;
}