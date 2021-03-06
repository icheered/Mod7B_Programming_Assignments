/// \file
/// main.cpp

/*
 *  Created on: Jan 29, 2015
 *      Author:
 *       Group:
 */ 
//altered by:
//==============================================================
// Filename : main.cpp
// Authors : Tjeerd Bakker and Soenke van Loh
// Version : 1
// License :
// Description : changes in the given main.cpp in order to use the functionality that was written for the pacman game from our own files
//==============================================================


#include "GameObjectStruct.h"
#include "LevelClass.h"
#include "UI.h"
#include <SDL2/SDL.h>
#include <vector>
#include <array>
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
    // Dereference the passed paramenters
    LevelClass* level = (LevelClass*)params;
    
    // Handle user input
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP])
        level->handleInput(UP);
    else if (state[SDL_SCANCODE_DOWN])
        level->handleInput(DOWN);
    else if (state[SDL_SCANCODE_LEFT])
        level->handleInput(LEFT);
    else if (state[SDL_SCANCODE_RIGHT])
        level->handleInput(RIGHT);  

    // Move the objects and check for collission
    level->move();
    level->checkCollision();

    return interval;
}

/// Program entry point.
int main(int /*argc*/, char ** /*argv*/)
{
    srand (time(NULL));

    // Get the map
    std::vector<std::vector<int>> map = {{
        #include "board.def"
    }};


    // Some coordinates for entities
    std::vector<int> pacmanSpawn {13, 15};

    std::vector<std::vector<int>> ghostSpawns {
        {12,13},
        {13,13},
        {14,13},
        {15,13},
    };

    std::vector<std::vector<int>> energizers {
        {1,1},
        {1,25},
        {26,1},
        {26,25},
        {18,11},
        {9,11}
    };


    // Fill board with dots
    int dots = 0;
    for(auto &row : map) {
        for(auto &col : row) {
            if(col == 0){
                col = 3;
                dots++;
            }
            //std::cout << col << " ";  // Print the map
        }
        //std::cout << std::endl;
    }

    // Create energizers on the map
    for(auto &loc : energizers) {
        dots--;
        map[loc[1]][loc[0]] = 2;
    }
    // Remove dots on ghost spawn locations
    for(auto &loc : ghostSpawns) {
        dots--;
        map[loc[1]][loc[0]] = 0;
    }
    // Remove dot on pacman spawn location
    map[pacmanSpawn[1]][pacmanSpawn[0]] = 0;
    dots--;

    std::vector<std::vector<int>> initialMap = map;
    int initialDots = dots;
    

    // Create a new ui object, pass pointer to map
    UI ui(&map);
    
    // Create all game objects, pass pointer to map
    LevelClass level = LevelClass(&map, ghostSpawns, dots);


    // Start timer for game update, call this function every 50 ms.
    SDL_TimerID timer_id =
        SDL_AddTimer(50, gameUpdate, &level);

    
    bool quit = false;
    std::cout << "Game Started" << std::endl;
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
        //restart Level
        if(level.getRestart()) {
            map = initialMap;
            dots = initialDots;
            level = LevelClass(&map, ghostSpawns, dots);
        }

        //add one extra life when player hits 10k points
        if (!level.getExtraLife())
            level.setExtraLife();

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
