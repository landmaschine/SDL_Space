#pragma once
#include "Icamera.h"

class Camera : public ICamera {
public:
    Camera() {
        cam.w = 800;
        cam.h = 600;
        cam.x = 400;
        cam.y = 300;
        worldW = 800;
        worldH = 600;
    }

    void easing(IPlayer &player, Iwindow& win, float modifier) override;

    SDL_FRect& rect() override {
        return cam;
    }

private:
    SDL_FRect cam;
    int worldW, worldH;
};