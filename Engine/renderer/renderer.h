#pragma once
#include "Irenderer.h"
#include "../window/Iwindow.h"

class Renderer : public Irenderer {
    public:
        Renderer(Iwindow& window) : _windowPtr(window.windowP()) {
            if(_windowPtr == nullptr) {
                std::cout << "Failed to init renderer, window pointer error!\n";
            }
            _renderer = SDL_CreateRenderer(_windowPtr, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            std::cout << "Renderer created!\n";
        }
        
        ~Renderer() {SDL_DestroyRenderer(_renderer);}

        SDL_Renderer* renderer() override {
            return _renderer;
        }

    private:
        SDL_Renderer* _renderer;
        SDL_Window* _windowPtr;
};