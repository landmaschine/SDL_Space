#include "player.h"

void Player::draw(float cameraX, float cameraY) {
    SDL_FRect adjustedRect = {playerDst_Rect.x - cameraX, playerDst_Rect.y - cameraY, playerDst_Rect.w, playerDst_Rect.h};

    SDL_RenderCopyExF(renderer, objTex, nullptr, &adjustedRect, rot, nullptr, SDL_FLIP_NONE);
}