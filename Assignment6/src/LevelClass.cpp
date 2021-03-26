#pragma once

#include "LevelClass.h"
#include <iostream>

LevelClass::LevelClass(std::vector<std::vector<int>> *newmap, std::vector<std::vector<int>> ghostSpawns, int numberOfDots){
    dots = numberOfDots;
    map = newmap;
    pacman.setSpeed(0.25);
    pacman.setEpsilon(epsilon);
    pacman.setMap(map);

    // Create ghosts, pass their behaviour/name as argument
    Ghost blinky(ghostSpawns[0][0], ghostSpawns[0][1], "blinky", BLINKY);
    blinky.setSpeed(0.25);
    blinky.setMap(map);
    blinky.setEpsilon(epsilon);
    Ghost pinky(ghostSpawns[1][0], ghostSpawns[1][1], "pinky", PINKY);
    pinky.setSpeed(0.25);
    pinky.setMap(map);
    pinky.setEpsilon(epsilon);
    Ghost inky(ghostSpawns[2][0], ghostSpawns[2][1], "inky", INKY);
    inky.setSpeed(0.25);
    inky.setMap(map);
    inky.setEpsilon(epsilon);
    Ghost clyde(ghostSpawns[3][0], ghostSpawns[3][1], "clyde", CLYDE);
    clyde.setSpeed(0.25);
    clyde.setMap(map);
    clyde.setEpsilon(epsilon);

    ghosts.push_back(blinky);
    ghosts.push_back(pinky);
    ghosts.push_back(inky);
    ghosts.push_back(clyde);

    // set dots, score, lives
    score = 0;
    lives = 3;
}

bool LevelClass::getRestart() {
    return restart; }

bool LevelClass::getExtraLife() { return extraLife; }

void LevelClass::setExtraLife()
{
    if (getScore() > 10000) {
        extraLife = true;
        pacman.extraLife();
    }
}

void LevelClass::move(){
    pacman.move();

    for (auto &g : ghosts) {
        //ghost behave differently depending on the state of the game
        if (g.getFrightened()) {
            g.Behaviour(pacman.getX(), pacman.getY(), ghosts[0].getX(),
                        ghosts[0].getY(), pacman.getDirection(), 'f'); //frightend behaviour
        }
        else if (scatter) {
            scatterCount += 10;
            if (scatterCount > 2000)
                scatter = false;
        g.Behaviour(pacman.getX(), pacman.getY(), ghosts[0].getX(), ghosts[0].getY(), pacman.getDirection(), 's'); //scatter behaviour
        }
        else {
            scatterCount--;
            if (scatterCount < 1)
                scatter = true;
            g.Behaviour(pacman.getX(), pacman.getY(), ghosts[0].getX(), ghosts[0].getY(), pacman.getDirection(), 'c'); //chase behaviour
        }
    }

}

void LevelClass::handleInput(Direction direc){
    if(pacman.canRotate(direc)) { pacman.setDirectin(direc); }
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
    int oldScore = score;
    score += pacman.eatPowerup();
    if(oldScore % 500 > score % 500) {
        spawnFruit();
    }
    for (auto &g : ghosts) {
        g.setFrightened(true);
        g.setTimeout(100);
    }
}


void LevelClass::hitGhost(Ghost &g) {
    if(pacman.isChungus() && g.getFrightened()){
        g.die();
        int oldScore = score;
        score += 100;
        if(oldScore % 500 > score % 500) {
            spawnFruit();
        }
    }
    else if(g.getType() != SCAREDINV && !g.getFrightened()){
        resetLevel();
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
        int oldScore = score;
        score += 10;
        if(oldScore % 500 > score % 500) {
            spawnFruit();
        }
        dots--;
        if(dots == 0) {
            gameWon();
        }
    }

    // Check collision with fruits
    // A new fruit can't spawn by eating a fruit
    if((*map)[round(py)][round(px)] == 4) { score += 100; (*map)[round(py)][round(px)] = 0;} // Cherry
    if((*map)[round(py)][round(px)] == 5) { score += 200; (*map)[round(py)][round(px)] = 0;} // Strawberry
    if((*map)[round(py)][round(px)] == 6) { score += 300; (*map)[round(py)][round(px)] = 0;} // Orange
    if((*map)[round(py)][round(px)] == 7) { score += 500; (*map)[round(py)][round(px)] = 0;} // Lemon
    if((*map)[round(py)][round(px)] == 8) { score += 700; (*map)[round(py)][round(px)] = 0;} // Apple
    if((*map)[round(py)][round(px)] == 9) { score += 1000; (*map)[round(py)][round(px)] = 0;} // Grapes

    
    
}

void LevelClass::gameWon(){
    std::cout << "Win" << std::endl;
    restart = true;
}

void LevelClass::spawnFruit() {
    std::cout << "Spawn fruit" << std::endl;
    int fruit = rand() % 6 + 4;
    (*map)[15][13] = fruit;
}