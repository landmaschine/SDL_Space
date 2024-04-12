#pragma once
#include "IBackground.h"
#include "../texture/Texture.h"
#include "../renderer/renderer.h"
#include "../window/window.h"

class Background : public IBackground  {
    public:
        Background(Irenderer& _renderer) : renderer(_renderer.renderer()) {
            loadBackground();
            backRect.h = 1080;
            backRect.w = 1920;
            backRect.x = 0;
            backRect.y = 0;
        };

        void draw(float cameraX, float cameraY) override;

        SDL_FRect& rect() override {
            return backRect;
        }
    private:
        void loadBackground();
        Texturemanager backgroundLoad;
        SDL_Texture* backtex;
        SDL_Renderer* renderer;
        SDL_FRect backRect;
};