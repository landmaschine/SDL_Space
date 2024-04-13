#pragma once
#include <cmath>
#include "Iplayer.h"
#include "../math/vec2D.h"

class Player : public IPlayer {
    public:
        Player(Irenderer& _renderer) : renderer(_renderer.renderer()) {}
        void initObj(Iwindow& win, int _w, int _h, float _mass, float _friction) override {
            playerDst_Rect.x = (win.winRec().w / 2) - (_w / 2);
            playerDst_Rect.y = (win.winRec().h / 2) - (_h / 2);
            playerDst_Rect.h = 100;
            playerDst_Rect.w = 100;

            playerSrc_Rect.x = (win.winRec().w / 2) - (_w / 2);
            playerSrc_Rect.y = (win.winRec().h / 2) - (_h / 2);
            playerSrc_Rect.h = 100;
            playerSrc_Rect.w = 100;

            mass_ = _mass;
            deacell = _friction;
            vel.x = 1;
            vel.y = 1;
        }
        
        void draw() override;
        
        SDL_FRect& dstRect() override {
            return playerDst_Rect;
        }

        SDL_Rect& srcRect() override {
            return playerSrc_Rect;
        }

        Vector2<float>& directionVec() override {
            return directionvec;
        }

        Vector2<float>& velocity() override {
            return vel;
        }

        int& speedMod() override {
            return speedmod;
        }

        float& angle() override {
            return rot;
        }

        Vector2<float>& angleVec() override {
            return anglevec;
        }
 
        void tex(SDL_Texture* texture) override {
            objTex = texture;
        }

        float& deacelleration() override {
            return deacell;
        }

        float& mass() override {
            return mass_;
        }

    private:
        SDL_Texture* objTex;
        SDL_Rect playerSrc_Rect;
        SDL_FRect playerDst_Rect;
        SDL_Renderer* renderer;
        Vector2<float> vel;
        Vector2<float> anglevec;
        Vector2<float> directionvec;
        float rot;
        float mass_;
        float deacell;
        int speedmod;
};