/// \file
/// main.cpp

/*
 *  Created on: Jan 29, 2015
 *      Author:
 *       Group:
 */

#include "GameObjectStruct.h"
#include "LevelClass.h"
#include "UI.h"
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>

/// Callback function to update the game state.
///
/// This function is called by an SDL timer at regular intervals.
/// Note that this callback may happen on a different thread than the main thread.
/// You therefore have to be careful in avoiding data races. For example, you
/// should use mutexes to access shared data.
/// Read the documentation of SDL_AddTimer for more information and for tips
/// regarding multithreading issues.
Uint32 gameUpdate(Uint32 interval, void * params)
{
    // Do game loop update here
    LevelClass* level = (LevelClass*)params;
    
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP])
        level->handleInput(UP);
    else if (state[SDL_SCANCODE_DOWN])
        level->handleInput(DOWN);
    else if (state[SDL_SCANCODE_LEFT])
        level->handleInput(LEFT);
    else if (state[SDL_SCANCODE_RIGHT])
        level->handleInput(RIGHT);  

    level->move();
    level->checkCollision();

    // Move objects
    // Check for collission

    return interval;
}

/// Program entry point.
int main(int /*argc*/, char ** /*argv*/)
{
    std::vector<std::vector<int>> map = {{
        #include "board.def"
    }};

    map[1][4] = 2;
    

    for(auto &row : map) {
        for(auto &col : row) {
            std::cout << col << " ";
        }
        std::cout << std::endl;
    }
    
    // Create a new ui object
    UI ui(&map); // <-- use map from your game objects.
    

    
    // Call game init code here
    // Create pacman, ghosts, lives, score
    // Example object, this can be removed later

    LevelClass level = LevelClass(&map);

    // Start timer for game update, call this function every 100 ms.
    SDL_TimerID timer_id =
        SDL_AddTimer(10, gameUpdate, &level);

    
    bool quit = false;
    while (!quit) {
        // set timeout to limit frame rate
        Uint32 timeout = SDL_GetTicks() + 20;

        // Handle the input
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            // Quit button.
            if (e.type == SDL_QUIT) {
                quit = true;
            }

            // All keydown events
            if (e.type == SDL_KEYDOWN) {
                if(e.key.keysym.sym == SDLK_ESCAPE)
                    quit = true;
            }
        }

        // Set the score
        ui.setScore(level.getScore()); // <-- Pass correct value to the setter

        // Set the amount of lives
        ui.setLives(level.getLives()); // <-- Pass correct value to the setter

        // Render the scene
        std::vector<GameObjectStruct> objects = level.getObjects();
        // ^-- Your code should provide this vector somehow (e.g.
        // game->getStructs())
        ui.update(objects);

        while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
            // ... do work until timeout has elapsed
        }
    }

    SDL_RemoveTimer(timer_id);

    return 0;
}
