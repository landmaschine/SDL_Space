#include "input.h"

bool Inputhandler::input(IPlayer &obj, IMovement &move, Iwindow& window, ICamera& cam) {
    while(SDL_PollEvent(&event)) {
        if(event.type == SDL_QUIT) {
            return false;
        }

        const Uint8* state = SDL_GetKeyboardState(nullptr);
        if (state[SDL_KEYUP] && !state[SDL_KEYDOWN]) {
            obj.directionVec().x = 0;
            obj.directionVec().y = 0;
            obj.speedMod() = 1;
            obj.angle() = 1;
            a = false;
            b = false;
        }

        if(state[SDL_SCANCODE_ESCAPE]) {
            return false;
        }

        obj.directionVec().x = 0;
        obj.directionVec().y = 0;
        a = false;
        b = false;

        if (state[SDL_SCANCODE_W]) {
            obj.directionVec().y = 1.0f;
            obj.directionVec().x = 1.0f;
        }
        if (state[SDL_SCANCODE_S]) {
            obj.directionVec().y = -1.0f;
            obj.directionVec().x = -1.0f;
        }
        if (state[SDL_SCANCODE_A]) {
            b = true;
        }
        if (state[SDL_SCANCODE_D]) {
            a = true;
        }
        if(state[SDL_SCANCODE_LSHIFT]) {
            obj.speedMod() = 2;
        }
        if(state[SDL_SCANCODE_F11]) {
            winFlag = !winFlag;
            window.fullscreen(winFlag, obj);
        }

        if(event.type == SDL_WINDOWEVENT) {
        switch(event.window.event) {
            case SDL_WINDOWEVENT_RESIZED:
                    window.resizeUpdate(obj, cam);
                    break;
                 SDL_WINDOW_FULLSCREEN:
                    window.resizeUpdate(obj, cam);
                    break;
            }
        }

        SDL_GetMouseState(&mouseX, &mouseY);
        mousepos.x = mouseX;
        mousepos.y = mouseY;
    }
    return true;
}

void Inputhandler::windowEvents() {
    switch (event.type) {

    }
}