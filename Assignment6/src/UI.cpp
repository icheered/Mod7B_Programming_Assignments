/// \file
/// UI.cpp

/*
 *  Created on: Jan 29, 2015
 *      Author: frits
 *       Group: TA's
 */

#include "UI.h"

#include <iostream>

UI::UI(std::vector<std::vector<int>> *newmap)
{
    // Initialize and load textures.
    this->init();
    this->loadTextures();

    // Set the map
    map = newmap;
}

UI::~UI()
{
    SDL_DestroyTexture(sheet);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void UI::update(std::vector<GameObjectStruct> objects)
{
    // Clear the current renderer.
    
    //SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red Background 
    SDL_RenderClear(renderer);

    // Draw the walls.
    drawBackground(map);

    // Draw the score.
    drawScore();

    // Draw the lives.
    drawLives();

    // Loop through all the objects and draw them.
    for (auto &element : objects) {
        SDL_Rect dst = {element.x * TILESIZE, element.y * TILESIZE, TILESIZE,
                        TILESIZE};
        SDL_RenderCopy(renderer, sheet, &clips[element.type][element.dir],
                       &dst);
    }

    // Update the screen.
    SDL_RenderPresent(renderer);
}

void UI::drawScore()
{
    int digitSelector = 1; // 1 selects 0, 10 selects 1, ...
    int digit = 0;         // Digit to select

    // Loop through digits
    while (digitSelector < 100000) {
        // Destination rectangle
        SDL_Rect dst = {100 - digit * TILESIZE, 27 * TILESIZE, TILESIZE,
                        TILESIZE};

        // Get the current digit
        int value = (score / digitSelector) % 10;

        // Add to the renderer
        SDL_RenderCopy(renderer, sheet, &clips[(Type)(ZERO + value)][UP], &dst);

        // Select next digit
        digitSelector *= 10;
        digit++;
    }
}

// Draws an amount of pacmans corresponding to the amount of lives
void UI::drawLives()
{
    for (int i = 0; i < lives; i++) {
        SDL_Rect dst = {27 * TILESIZE - i * TILESIZE, 27 * TILESIZE, TILESIZE,
                        TILESIZE};
        SDL_RenderCopy(renderer, sheet, &clips[PACMAN][LEFT], &dst);
    }
}

void UI::setScore(int score) { this->score = score; }

void UI::setLives(int lives) { this->lives = lives; }

/// Initialises the UI::window and the UI::renderer.
void UI::init()
{
    // Init SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    // Create a Window in the middle of the screen
    window = SDL_CreateWindow("Pacman", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, 28 * TILESIZE,
                              27 * TILESIZE + (TILESIZE + 4), SDL_WINDOW_SHOWN);

    // Create a new renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                                  SDL_RENDERER_PRESENTVSYNC);
}

void UI::loadTextures()
{
    // Load sprite sheet
    #ifdef __linux__ 
        sheet = this->loadTexture("resources/sam_gfx.bmp");
    #elif _WIN32
        sheet = this->loadTexture("C:/Users/soenk/Documents/mod7/programming/Code/Mod7B_Programming_Assignments/Assignment6/resources/sam_gfx.bmp");
    #else
    #endif

    loadMaps();
}

void UI::loadMaps()
{
    const int size = TILESIZE;
    const int o = 4; // offset in bitmap (both in x and y)

    // Display the sprites. Every direction with an 'A' suffix is a different
    // Sprite for the same entity to animate the entity.
    std::map<Direction, SDL_Rect> pacman;
    pacman[UP] = {o + size * 1, o + size * 11, size, size};
    pacman[UPA] = {o + size * 3, o + size * 11, size, size};
    pacman[DOWN] = {o + size * 13, o + size * 7, size, size};
    pacman[DOWNA] = {o + size * 15, o + size * 7, size, size};
    pacman[LEFT] = {o + size * 0, o + size * 11, size, size};
    pacman[LEFTA] = {o + size * 2, o + size * 11, size, size};
    pacman[RIGHT] = {o + size * 12, o + size * 7, size, size};
    pacman[RIGHTA] = {o + size * 14, o + size * 7, size, size};
    clips[PACMAN] = pacman;

    std::map<Direction, SDL_Rect> pinky;
    pinky[UP] = {o + size * 6, o + size * 9, size, size};
    pinky[UPA] = {o + size * 7, o + size * 9, size, size};
    pinky[DOWN] = {o + size * 2, o + size * 9, size, size};
    pinky[DOWNA] = {o + size * 3, o + size * 9, size, size};
    pinky[RIGHT] = {o + size * 0, o + size * 9, size, size};
    pinky[RIGHTA] = {o + size * 1, o + size * 9, size, size};
    pinky[LEFT] = {o + size * 4, o + size * 9, size, size};
    pinky[LEFTA] = {o + size * 5, o + size * 9, size, size};
    clips[PINKY] = pinky;

    std::map<Direction, SDL_Rect> blinky;
    blinky[UP] = {o + size * 6, o + size * 7, size, size};
    blinky[UPA] = {o + size * 7, o + size * 7, size, size};
    blinky[DOWN] = {o + size * 2, o + size * 7, size, size};
    blinky[DOWNA] = {o + size * 3, o + size * 7, size, size};
    blinky[RIGHT] = {o + size * 0, o + size * 7, size, size};
    blinky[RIGHTA] = {o + size * 1, o + size * 7, size, size};
    blinky[LEFT] = {o + size * 4, o + size * 7, size, size};
    blinky[LEFTA] = {o + size * 5, o + size * 7, size, size};
    clips[BLINKY] = blinky;

    std::map<Direction, SDL_Rect> clyde;
    clyde[UP] = {o + size * 6, o + size * 10, size, size};
    clyde[UPA] = {o + size * 7, o + size * 10, size, size};
    clyde[DOWN] = {o + size * 2, o + size * 10, size, size};
    clyde[DOWNA] = {o + size * 3, o + size * 10, size, size};
    clyde[RIGHT] = {o + size * 0, o + size * 10, size, size};
    clyde[RIGHTA] = {o + size * 1, o + size * 10, size, size};
    clyde[LEFT] = {o + size * 4, o + size * 10, size, size};
    clyde[LEFTA] = {o + size * 5, o + size * 10, size, size};
    clips[CLYDE] = clyde;

    std::map<Direction, SDL_Rect> inky;
    inky[UP] = {o + size * 14, o + size * 9, size, size};
    inky[UPA] = {o + size * 15, o + size * 9, size, size};
    inky[DOWN] = {o + size * 10, o + size * 9, size, size};
    inky[DOWNA] = {o + size * 11, o + size * 9, size, size};
    inky[LEFT] = {o + size * 12, o + size * 9, size, size};
    inky[LEFTA] = {o + size * 13, o + size * 9, size, size};
    inky[RIGHT] = {o + size * 8, o + size * 9, size, size};
    inky[RIGHTA] = {o + size * 9, o + size * 9, size, size};
    clips[INKY] = inky;

    std::map<Direction, SDL_Rect> scared;
    scared[UP] = {o + size * 12, o + size * 6, size, size};
    scared[UPA] = scared[UP];
    scared[DOWN] = scared[UP];
    scared[DOWNA] = scared[UP];
    scared[LEFT] = scared[UP];
    scared[LEFTA] = scared[UP];
    scared[RIGHT] = scared[UP];
    scared[RIGHTA] = scared[UP];
    clips[SCARED] = scared;

    std::map<Direction, SDL_Rect> scaredinv;
    scaredinv[UP] = {o + size * 4, o + size * 11, size, size};
    scaredinv[UPA] = scaredinv[UP];
    scaredinv[DOWN] = scaredinv[UP];
    scaredinv[DOWNA] = scaredinv[UP];
    scaredinv[LEFT] = scaredinv[UP];
    scaredinv[LEFTA] = scaredinv[UP];
    scaredinv[RIGHT] = scaredinv[UP];
    scaredinv[RIGHTA] = scaredinv[UP];
    clips[SCAREDINV] = scaredinv;

    std::map<Direction, SDL_Rect> strawberry;
    strawberry[UP] = {o + size * 1, o + size * 5, size, size};
    strawberry[DOWN] = strawberry[UP];
    strawberry[LEFT] = strawberry[UP];
    strawberry[RIGHT] = strawberry[UP];
    clips[STRAWBERRY] = strawberry;

    std::map<Direction, SDL_Rect> cherry;
    cherry[UP] = {o + size * 0, o + size * 5, size, size};
    cherry[DOWN] = cherry[UP];
    cherry[LEFT] = cherry[UP];
    cherry[RIGHT] = cherry[UP];
    clips[CHERRY] = cherry;

    std::map<Direction, SDL_Rect> orange;
    orange[UP] = {o + size * 2, o + size * 5, size, size};
    orange[DOWN] = orange[UP];
    orange[LEFT] = orange[UP];
    orange[RIGHT] = orange[UP];
    clips[ORANGE] = orange;

    std::map<Direction, SDL_Rect> lemon;
    lemon[UP] = {o + size * 3, o + size * 5, size, size};
    lemon[DOWN] = lemon[UP];
    lemon[LEFT] = lemon[UP];
    lemon[RIGHT] = lemon[UP];
    clips[LEMON] = lemon;

    std::map<Direction, SDL_Rect> apple;
    apple[UP] = {o + size * 4, o + size * 5, size, size};
    apple[DOWN] = apple[UP];
    apple[LEFT] = apple[UP];
    apple[RIGHT] = apple[UP];
    clips[APPLE] = apple;

    std::map<Direction, SDL_Rect> grapes;
    grapes[UP] = {o + size * 5, o + size * 5, size, size};
    grapes[DOWN] = grapes[UP];
    grapes[LEFT] = grapes[UP];
    grapes[RIGHT] = grapes[UP];
    clips[GRAPES] = grapes;

    std::map<Direction, SDL_Rect> dot;
    dot[UP] = {o + 12 * 16, o + 12 * 0, size / 2, size / 2};
    dot[DOWN] = dot[UP];
    dot[LEFT] = dot[UP];
    dot[RIGHT] = dot[UP];
    clips[DOT] = dot;

    std::map<Direction, SDL_Rect> energizer;
    energizer[UP] = {o + 12 * 18, o + 12 * 0, size / 2, size / 2};
    energizer[DOWN] = energizer[UP];
    energizer[LEFT] = energizer[UP];
    energizer[RIGHT] = energizer[UP];
    clips[ENERGIZER] = energizer;

    std::map<Direction, SDL_Rect> wall;
    wall[UP] = {o + size * 6, o + size * 11, size, size};
    wall[DOWN] = wall[UP];
    wall[LEFT] = wall[UP];
    wall[RIGHT] = wall[UP];
    clips[WALL] = wall;

    for (int i = 0; i < 10; i++) {
        std::map<Direction, SDL_Rect> nr;
        nr[UP] = {o + (size / 2) * i, o + 1 + size * 0, size / 2, size / 2};
        nr[UPA] = nr[UP];
        nr[DOWN] = nr[UP];
        nr[DOWNA] = nr[UP];
        nr[LEFT] = nr[UP];
        nr[LEFTA] = nr[UP];
        nr[RIGHT] = nr[UP];
        nr[RIGHTA] = nr[UP];
        clips[(Type)(ZERO + i)] = nr;
    }
}

void UI::drawBackground(std::vector<std::vector<int>> *map)
{
    // Draw the map
    // 1 = Wall
    // 2 = Energizer
    // 3 = Dot
    // 4-8 = Fruit
    for (size_t i = 0; i < (*map).size(); i++) {
        for (size_t j = 0; j < (*map)[i].size(); j++) {
            if ((*map)[i][j] == 1) {
                SDL_Rect dst = {static_cast<int>(j) * TILESIZE,
                                static_cast<int>(i) * TILESIZE, TILESIZE,
                                TILESIZE};
                SDL_RenderCopy(renderer, sheet, &clips[WALL][DOWN], &dst);
            }
            else if((*map)[i][j] == 2) {
                SDL_Rect dst = {static_cast<int>(j) * TILESIZE,
                                static_cast<int>(i) * TILESIZE, TILESIZE,
                                TILESIZE};
                SDL_RenderCopy(renderer, sheet, &clips[ENERGIZER][DOWN], &dst);
            }
            else if((*map)[i][j] == 3) {
                SDL_Rect dst = {static_cast<int>(j) * TILESIZE,
                                static_cast<int>(i) * TILESIZE, TILESIZE,
                                TILESIZE};
                SDL_RenderCopy(renderer, sheet, &clips[DOT][DOWN], &dst);
            }
            else if((*map)[i][j] == 4) {
                SDL_Rect dst = {static_cast<int>(j) * TILESIZE,
                                static_cast<int>(i) * TILESIZE, TILESIZE,
                                TILESIZE};
                SDL_RenderCopy(renderer, sheet, &clips[CHERRY][DOWN], &dst);
            }
            else if((*map)[i][j] == 5) {
                SDL_Rect dst = {static_cast<int>(j) * TILESIZE,
                                static_cast<int>(i) * TILESIZE, TILESIZE,
                                TILESIZE};
                SDL_RenderCopy(renderer, sheet, &clips[STRAWBERRY][DOWN], &dst);
            }
            else if((*map)[i][j] == 6) {
                SDL_Rect dst = {static_cast<int>(j) * TILESIZE,
                                static_cast<int>(i) * TILESIZE, TILESIZE,
                                TILESIZE};
                SDL_RenderCopy(renderer, sheet, &clips[ORANGE][DOWN], &dst);
            }
            else if((*map)[i][j] == 7) {
                SDL_Rect dst = {static_cast<int>(j) * TILESIZE,
                                static_cast<int>(i) * TILESIZE, TILESIZE,
                                TILESIZE};
                SDL_RenderCopy(renderer, sheet, &clips[LEMON][DOWN], &dst);
            }
            else if((*map)[i][j] == 8) {
                SDL_Rect dst = {static_cast<int>(j) * TILESIZE,
                                static_cast<int>(i) * TILESIZE, TILESIZE,
                                TILESIZE};
                SDL_RenderCopy(renderer, sheet, &clips[APPLE][DOWN], &dst);
            }
            else if((*map)[i][j] == 9) {
                SDL_Rect dst = {static_cast<int>(j) * TILESIZE,
                                static_cast<int>(i) * TILESIZE, TILESIZE,
                                TILESIZE};
                SDL_RenderCopy(renderer, sheet, &clips[GRAPES][DOWN], &dst);
            }
        }
    }
}

SDL_Texture *UI::loadTexture(const std::string &file)
{
    // Load the bitmap. This gave some issues on windows, hence this #ifdef statement
    #ifdef __linux__ 
        SDL_Surface *surf = SDL_LoadBMP("resources/sam_gfx.bmp");
    #elif _WIN32
        SDL_Surface *surf = SDL_LoadBMP("C:/Users/soenk/Documents/mod7/programming/Code/Mod7B_Programming_Assignments/Assignment6/resources/sam_gfx.bmp");
    #else
    #endif

    
    if (surf == nullptr) {
        std::cerr << "Error while loading texture bitmap: " << SDL_GetError() << std::endl;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr) {
        std::cerr << "Error while creating texture: " << SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(surf);
    return texture;
}
