/*
 *  Created on: May 14, 2018
 *      Author: Johan Engelen
 *  Ported from D source by same author.
 */

#ifndef SRC_UI_H_
#define SRC_UI_H_

#include <SDL2/SDL.h>

class UI
{
public:
    const int sizeX;
    const int sizeY;

    UI(int sizeX, int sizeY) : sizeX(sizeX), sizeY(sizeY)
    {
        initialize(sizeX, sizeY);
    }

    ~UI()
    {
        if (renderer)
            SDL_DestroyRenderer(renderer);
        if (window)
            SDL_DestroyWindow(window);
        SDL_Quit();
    }

    void clear()
    {
        setDrawColor(0, 0, 0, 255);
        SDL_RenderClear(renderer);
        setDrawColor(255, 255, 255, 255);
    }

    void present()
    {
        SDL_RenderPresent(renderer);
    }

    void drawPixel(int x, int y)
    {
        SDL_RenderDrawPoint(renderer, x + sizeX / 2, y + sizeY / 2);
    }

    void setDrawColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    {
        SDL_SetRenderDrawColor(renderer, r, g, b, a);
    }

private:
    void initialize(int sizeX, int sizeY)
    {
        SDL_Init(SDL_INIT_EVERYTHING);

        // Create a Window in the middle of the screen
        window = SDL_CreateWindow("Implicit contour", SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED, sizeX, sizeY, SDL_WINDOW_SHOWN);

        renderer = SDL_CreateRenderer(window, -1,
                SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
};

#endif /* SRC_UI_H_ */
