#pragma once
#include "I_input.h"

class Inputhandler : public I_input {
    public:
        bool input(IPlayer &obj, IMovement &move, Iwindow &window, ICamera& cam) override;
        Vector2<float>& mousePos() override {
            return mousepos;
        }

        void windowEvents();
        
        bool pressedA() override {
            return a;
        }

        bool pressedD() override {
            return b;
        }

    private:
        SDL_Event event;
        const Uint8* keystates = SDL_GetKeyboardState(NULL);
        int mouseX, mouseY;
        Vector2<float> mousepos;
        bool a, b;
        bool winFlag;
};