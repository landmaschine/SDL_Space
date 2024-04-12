#include "Background.h"

void Background::draw(float cameraX, float cameraY) {
    SDL_FRect adjustedRect = { backRect.x - cameraX, backRect.y - cameraY, backRect.w, backRect.h };

    SDL_RenderCopyF(renderer, backtex, nullptr, &adjustedRect);
}

void Background::loadBackground() {
    backtex = backgroundLoad.loadTexture(renderer, "/home/leonw/Documents/dev/SDL_Space/assets/background_Space1.png");
}