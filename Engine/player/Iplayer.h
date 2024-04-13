#pragma once
class IMovement;
class Irenderer;
#include <SDL2/SDL.h>
#include "../Engine/math/vec2D.h"
#include "../Engine/texture/Texture.h"
#include "../Engine/movement/Movement.h"
#include "../Engine/renderer/renderer.h"

class IPlayer {
    public:
        virtual void initObj(Iwindow& win, int w, int h, float _mass, float _deacell) = 0;
        virtual void draw() = 0;
        virtual SDL_FRect& dstRect() = 0;
        virtual SDL_Rect& srcRect() = 0;
        virtual Vector2<float>& velocity() = 0;
        virtual Vector2<float>& directionVec() = 0;
        virtual float& deacelleration() = 0;
        virtual float& mass() = 0;
        virtual int& speedMod() = 0;
        virtual float& angle() = 0;
        virtual Vector2<float>& angleVec() = 0;
        virtual void tex(SDL_Texture* texture) = 0;
};