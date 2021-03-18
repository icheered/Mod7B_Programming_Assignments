#pragma once

#include "LevelClass.h"

LevelClass::LevelClass(std::vector<std::vector<int>> startMap){
    map = startMap;

    pacman = Pacman();

    // Create ghosts, pass their behaviour/name as argument
    ghosts.push_back(Ghost());
    ghosts.push_back(Ghost());
    ghosts.push_back(Ghost());
    ghosts.push_back(Ghost());

    // set dots, score, lives
    dots = 100;
    score = 0;
    lives = 3;
}

void LevelClass::move(){
    switch(pacman.getDirection()){
        case "UP": {
            if(!(map[round(pacman.getX())][round(pacman.getY())+1]))
                pacman.setY(pacman.getY()+pacman.getSpeed());
            }
            break;
        case "RIGHT": {
            if(!(map[round(pacman.getX()+1)][round(pacman.getY())]))
                pacman.setY(pacman.getX()+pacman.getSpeed());
            }
            break;
        case "DOWN": {
            if(!(map[round(pacman.getX())][round(pacman.getY())-1]))
                pacman.setY(pacman.getY()-pacman.getSpeed());
            }
            break;
        case "LEFT": {
            if(!(map[round(pacman.getX()-1)][round(pacman.getY())]))
                pacman.setY(pacman.getY()-pacman.getSpeed());
            }
            break;
    }
    int a = 3;
}

void LevelClass::checkCollision() {

}