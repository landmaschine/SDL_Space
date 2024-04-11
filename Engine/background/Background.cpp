#include "Background.h"

void Background::draw() {
    SDL_RenderCopyF(renderer, backtex, nullptr, &backRect);
}

void Background::loadBackground() {
    backtex = backgroundLoad.loadTexture(renderer, "/home/leonw/Documents/dev/SDL_Space/assets/background_Space1.png");
}