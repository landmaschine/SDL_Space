#pragma once
class IPlayer;
class ICamera;
#include <SDL2/SDL.h>
#include <iostream>

class Iwindow {
    public:
    virtual SDL_Window* windowP() = 0;
    virtual SDL_Rect winRec() = 0;
    virtual void resizeUpdate(IPlayer &player, ICamera& cam) = 0;
    virtual void fullscreen(bool flag, IPlayer& player) = 0;
};