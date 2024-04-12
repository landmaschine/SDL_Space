#include "space.h"

space::space() : inputhandler(), window(800, 600), renderer(window), backgroundmanager(renderer), player(renderer) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "Failed to init SDL!\n";
    }else{
        std::cout << "SDL Successfully initialised!\n";
    }

    player.initObj(window, 100, 100, 1, 0.7);
    player.tex(texturemanager.loadTexture(renderer.renderer(), "/home/leonw/Documents/dev/SDL_Space/assets/SpaceSphipV2.png"));
}

void space::run() {
    int startTicks = SDL_GetTicks();

    double newTime = utils::hireTimeInSeconds();
    double frametime = newTime - currentTime;

    if(frametime > 0.25f) {frametime = 0.25f;}

    currentTime = newTime;
    accumulator += frametime;

    input();

    while(accumulator >= timeStep) {
        update(frametime);
        render();
        accumulator -= frametime;
    }
}

void space::input() {
    runner = inputhandler.input(player, playerMove, window, camera);
}

void space::update(double dt) {
    playerMove.playerPosUpdate(player, inputhandler, dt);
    playerMove.playerRotUpdate(player, inputhandler, dt);
    camera.easing(player, window, 1);
}

void space::render() {
    SDL_RenderClear(renderer.renderer());
    backgroundmanager.draw(camera.rect().x, camera.rect().y);
    player.draw(camera.rect().x, camera.rect().y);
    SDL_RenderPresent(renderer.renderer());
}

void space::clean() {

}

space::~space() {
    clean();
    SDL_Quit();
}