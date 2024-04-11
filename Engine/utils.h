#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <iomanip>

namespace utils
{
    inline float hireTimeInSeconds()
    {
        double t = SDL_GetTicks64();
        t *= 0.001f;
        return t;
    }

    inline void Frames(int &frameCount, double &startTime)
    {
        frameCount++;

        double currentTime = SDL_GetTicks64();
        double elapsedTime = currentTime - startTime;

        if (elapsedTime >= 1000)
        {
            double fps = frameCount / (elapsedTime / 1000.0f);
            double frameTime = (1 / fps) / 1000;
            std::cout << "Fps: " << fps << " -- " << frameTime << " ms" << std::endl;

            startTime = currentTime;
            frameCount = 0;
        }
    }
}