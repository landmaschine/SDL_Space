#pragma once
class Iwindow;
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "../player/player.h"
#include "../movement/Movement.h"
#include "../window/window.h"

class I_input {
    public:
        virtual bool input(IPlayer &obj, IMovement &move, Iwindow& window) = 0;
        virtual Vector2<float>& mousePos() = 0;
        virtual bool pressedA() = 0;
        virtual bool pressedD() = 0;
};