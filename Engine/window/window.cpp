#include "window.h"
#include "../player/player.h"

Window::Window() {
    _width = 800;
    _height = 600;
    _windowP = SDL_CreateWindow("Space", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE);
    std::cout << "Window initialized!\n";
}

void Window::fullscreen(bool flag, IPlayer& player) {
    if(flag) {
        SDL_SetWindowFullscreen(_windowP, SDL_WINDOW_FULLSCREEN);
        SDL_SetWindowPosition(_windowP, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        int _w, _h;
        SDL_GetWindowSize(_windowP, &_w, &_h);
        player.dstRect().x = (_w / 2) - (player.srcRect().w / 2);
        player.dstRect().y = (_h / 2) - (player.srcRect().h / 2);
    } else {
        SDL_SetWindowFullscreen(_windowP, 0);
        SDL_SetWindowPosition(_windowP, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        int _w, _h;
        SDL_GetWindowSize(_windowP, &_w, &_h);
        player.dstRect().x = (_w / 2) - (player.srcRect().w / 2);
        player.dstRect().y = (_h / 2) - (player.srcRect().h / 2);
    }

}

void Window::resizeUpdate(IPlayer &player, ICamera& cam) {
    int _w, _h;
    SDL_GetWindowSize(_windowP, &_w, &_h);
    player.dstRect().x = (_w / 2) - (player.srcRect().w / 2);
    player.dstRect().y = (_h / 2) - (player.srcRect().h / 2);
}