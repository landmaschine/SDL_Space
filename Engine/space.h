#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "utils.h"
#include "../Engine/window/window.h"
#include "../Engine/renderer/renderer.h"
#include "../Engine/input/input.h"
#include "../Engine/movement/Movement.h"
#include "../Engine/texture/Texture.h"
#include "../Engine/background/Background.h"
#include "../Engine/player/player.h"
#include "../Engine/camera/Camera.h"

class space {
    public:
        space();
        ~space();
        void run();
        bool running() {return runner;}
    private:
        bool runner;
        const float timeStep = 0.005f;
        float accumulator = 0.0f;
        double currentTime;
        
        int frameCount = 0;
        double startTime = SDL_GetTicks64();

        void update(double dt);
        void input();
        void render();
        void clean();

        Window window;
        Renderer renderer;
        Inputhandler inputhandler;
        Player player;
        Movement playerMove;
        Texturemanager texturemanager;
        Background backgroundmanager;
        Camera camera;
};