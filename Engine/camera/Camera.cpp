#include "Camera.h"

void Camera::easing(IPlayer &player, Iwindow& win, float modifier) {
    int _w, _h;
    SDL_GetWindowSize(win.windowP(), &_w, &_h);
    cam.w = _w;
    cam.h = _h;

    cam.x = player.dstRect().x - (cam.w - player.srcRect().w) / 2;
    cam.y = player.dstRect().y - (cam.h - player.srcRect().h) / 2;
    
    if (cam.x < 0) {
        cam.x = 0;
    }
    if (cam.y < 0) {
        cam.y = 0;
    }
}