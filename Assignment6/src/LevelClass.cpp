#pragma once

#include "LevelClass.h"
#include <iostream>

LevelClass::LevelClass(std::vector<std::vector<int>> *newmap){
    map = newmap;
    pacman.setSpeed(0.05);

    // Create ghosts, pass their behaviour/name as argument

    Ghost blinky(8, 1, "blinky", BLINKY);
    Ghost pinky(9, 1, "pinky", PINKY);
    Ghost inky(10, 1, "inky", INKY);
    Ghost clyde(11, 1, "clyde", CLYDE);

    ghosts.push_back(blinky);
    ghosts.push_back(pinky);
    ghosts.push_back(inky);
    ghosts.push_back(clyde);

    // set dots, score, lives
    dots = 100;
    score = 0;
    lives = 3;
}

void LevelClass::move(){
    switch(pacman.getDirection()){
        case UP: {
            if(abs(floor(pacman.getX()) - pacman.getX()) < epsilon){
                if((*map)[floor(pacman.getY()-pacman.getSpeed())][floor(pacman.getX())] != 1)
                {
                    pacman.setY(pacman.getY()-pacman.getSpeed());
                    //std::cout << "Moving UP!" << std::endl;
                }
                else {
                    //std::cout << "UP is blocked!" << std::endl;
                }
            }
        }
            break;
        case DOWN: {
            if(abs(floor(pacman.getX()) - pacman.getX()) < epsilon){
                if((*map)[ceil(pacman.getY())][floor(pacman.getX())] != 1)
                {
                    pacman.setY(pacman.getY()+pacman.getSpeed());
                    //std::cout << "Moving DOWN!" << std::endl;
                }
                else {
                    //std::cout << "DOWN is blocked!" << std::endl;
                } 
            }
        }
            break;
        case LEFT: {
            if(abs(floor(pacman.getY()) - pacman.getY()) < epsilon){
                if((*map)[floor(pacman.getY())][floor(pacman.getX()-pacman.getSpeed())] != 1)
                {
                    pacman.setX(pacman.getX()-pacman.getSpeed());
                    //std::cout << "Moving LEFT!" << std::endl;
                }
                else {
                    //std::cout << "LEFT is blocked!" << std::endl;
                } 
            }
        }
            break;
        case RIGHT: {
            if(abs(floor(pacman.getY()) - pacman.getY()) < epsilon){
                if((*map)[floor(pacman.getY())][ceil(pacman.getX())] != 1)
                {
                    pacman.setX(pacman.getX()+pacman.getSpeed());
                    //std::cout << "Moving RIGHT!" << std::endl;
                }
                else {
                    //std::cout << "RIGHT is blocked!" << std::endl;
                }
            }
        }
            break;
    }
}

void LevelClass::handleInput(Direction direc){
    //std::cout << "Direction: " << direc << std::endl;
    switch(direc){
        case UP: {
            if(abs(floor(pacman.getX()) - pacman.getX()) < epsilon)
            {
                if((*map)[floor(pacman.getY()-pacman.getSpeed())][floor(pacman.getX())] != 1)
                {
                    //std::cout << "Rotating UP" << std::endl;
                    pacman.setDirectin(direc);
                }
                else {
                    //std::cout << "Won't rotate, UP blocked" << std::endl;
                }
            }
        } break;
        case DOWN: {
            if(abs(floor(pacman.getX()) - pacman.getX()) < epsilon)
            {
                if((*map)[ceil(pacman.getY()+pacman.getSpeed())][floor(pacman.getX())] != 1)
                {
                    //std::cout << "Rotating DOWN" << std::endl;
                    pacman.setDirectin(direc);
                }
                else {
                    //std::cout << "Won't rotate, DOWN blocked" << std::endl;
                }
            }
        } break;
        case LEFT: {
            if(abs(floor(pacman.getY()) - pacman.getY()) < epsilon)
            {
                if((*map)[floor(pacman.getY())][floor(pacman.getX()-pacman.getSpeed())] != 1)
                {
                    //std::cout << "Rotating  LEFT" << std::endl;
                    pacman.setDirectin(direc);
                }
                else {
                    //std::cout << "Won't rotate, LEFT blocked" << std::endl;
                }
            }
        } break;
        case RIGHT: {         
            
            if(abs(floor(pacman.getY()) - pacman.getY()) < epsilon)
            {
                if((*map)[floor(pacman.getY())][ceil(pacman.getX()+pacman.getSpeed())] != 1)
                {
                    //std::cout << "Rotating RIGHT" << std::endl;
                    pacman.setDirectin(direc);
                }
                else {
                    //std::cout << "Won't rotate, RIGHT blocked" << std::endl;
                }
            }
        } break;
    }
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

    // Check collision with energizer
    if((*map)[round(py)][round(px)] == 2){
        (*map)[round(py)][round(px)] = 0;
        LevelClass::ateEnergizer();
    }

    if((*map)[round(py)][round(px)] == 3){
        (*map)[round(py)][round(px)] = 0;
        score += 10;
    }

    
    // Check collision with powerups
    // Check collision with fruits
    // Check collision with dots
}