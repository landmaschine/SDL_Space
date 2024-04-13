#include "player.h"

void Player::draw() {
    SDL_RenderCopyExF(renderer, objTex, nullptr, &playerDst_Rect, rot, nullptr, SDL_FLIP_NONE);
}