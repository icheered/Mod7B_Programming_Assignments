#pragma once

#include "LevelClass.h"
#include <iostream>

LevelClass::LevelClass(std::vector<std::vector<int>> *newmap, std::vector<std::vector<int>> ghostSpawns, int numberOfDots){
    dots = numberOfDots;
    map = newmap;
    pacman.setSpeed(0.05);
    pacman.setEpsilon(epsilon);
    pacman.setMap(map);

    // Create ghosts, pass their behaviour/name as argument
    Ghost blinky(ghostSpawns[0][0], ghostSpawns[0][1], "blinky", BLINKY);
    Ghost pinky(ghostSpawns[1][0], ghostSpawns[1][1], "pinky", PINKY);
    Ghost inky(ghostSpawns[2][0], ghostSpawns[2][1], "inky", INKY);
    Ghost clyde(ghostSpawns[3][0], ghostSpawns[3][1], "clyde", CLYDE);

    ghosts.push_back(blinky);
    ghosts.push_back(pinky);
    ghosts.push_back(inky);
    ghosts.push_back(clyde);

    // set dots, score, lives
    score = 0;
    lives = 3;
}

bool LevelClass::getRestart() {
    return restart;
}

void LevelClass::move(){
    pacman.move();
}

void LevelClass::handleInput(Direction direc){
    //std::cout << "Direction: " << direc << std::endl;
    if(pacman.canRotate(direc)) { pacman.setDirectin(direc); }
    //else {std::cout<<"Can't" << std::endl;}
}

std::vector<GameObjectStruct> LevelClass::getObjects(){
    std::vector<GameObjectStruct> objects;
    objects.push_back(pacman);
    for (auto &x : ghosts) { 
        objects.push_back(x);
    }
    return objects;
}

int LevelClass::getScore(){
    return score;
}
int LevelClass::getLives(){
    return pacman.getLives();
}

void LevelClass::ateEnergizer() {
    score += pacman.eatPowerup();
    for (auto &g : ghosts) {
        g.setFrightened(true);
    }
}

void LevelClass::hitGhost(Ghost &g) {
    if(pacman.isChungus() && g.getType() == SCARED){
        g.die();
        score += 100;
    }
    else if(g.getType() != SCAREDINV){
        pacman.die();
    }
}


void LevelClass::resetLevel() {
    lives--;
    pacman.die();
    for (auto &g : ghosts) {
        g.respawn();
    }
}

void LevelClass::checkCollision() {
    double px = pacman.getX();
    double py = pacman.getY();

    // Check collision with ghosts
    bool doReset = false;
    for (auto &g : ghosts) { 
        if( px + 1 > g.x && g.x + 1 > px ){
            if( py + 1 > g.y && g.y + 1 > py ){
                // Pacman collides with ghost
                // Check if Pacman is bigChungus
                //std::cout << "Ghost Collision" << std::endl;
                LevelClass::hitGhost(g);
            }
        }
    }
    if(pacman.isDead()) { 
        std::cout << "Game Over" << std::endl;
        restart = true; 
    }

    // Check collision with energizer
    if((*map)[round(py)][round(px)] == 2){
        (*map)[round(py)][round(px)] = 0;
        LevelClass::ateEnergizer();
    }

    // Check collision with dot
    if((*map)[round(py)][round(px)] == 3){
        (*map)[round(py)][round(px)] = 0;
        score += 10;
        dots--;
        if(dots == 0) {
            gameWon();
        }
    }

    
    // Check collision with powerups
    // Check collision with fruits
    // Check collision with dots
}

void LevelClass::gameWon(){
    std::cout << "Win" << std::endl;
    restart = true;
}