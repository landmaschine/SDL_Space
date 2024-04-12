#pragma once 
#include "Iwindow.h"

class Window : public Iwindow {
    public:
        Window();
        Window(int width, int height) : _width(width), _height(height), _windowP(nullptr) {
            _windowP = SDL_CreateWindow("Space", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE);
            winRect.h = height;
            winRect.w = width;
            std::cout << "Window initialized!\n";
        }
        
        ~Window() {SDL_DestroyWindow(_windowP);}

        SDL_Window* windowP() override{
            return _windowP;
        };

        SDL_Rect winRec() {
            return winRect;
        }

        void fullscreen(bool flag, IPlayer &player) override;
        void resizeUpdate(IPlayer &player, ICamera& cam) override;

    private:
        SDL_Window* _windowP;
        int _width, _height;
        SDL_Rect winRect;
};