#pragma once

#include "LevelClass.h"
#include <iostream>

LevelClass::LevelClass(std::vector<std::vector<int>> startMap){
    map = startMap;
    pacman.setSpeed(0.05);

    // Create ghosts, pass their behaviour/name as argument

    Ghost blinky(13, 8, "blinky", BLINKY);
    Ghost pinky(14, 8, "pinky", PINKY);
    Ghost inky(15, 8, "inky", INKY);
    Ghost clyde(16, 8, "clyde", CLYDE);

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
                if(!(map[floor(pacman.getY()-pacman.getSpeed())][pacman.getX()]))
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
                if(!(map[ceil(pacman.getY())][pacman.getX()]))
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
                if(!(map[pacman.getY()][floor(pacman.getX()-pacman.getSpeed())]))
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
                if(!(map[pacman.getY()][ceil(pacman.getX())]))
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
                if(!(map[floor(pacman.getY()-pacman.getSpeed())][pacman.getX()]))
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
                if(!(map[ceil(pacman.getY()+pacman.getSpeed())][pacman.getX()]))
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
                if(!(map[pacman.getY()][floor(pacman.getX()-pacman.getSpeed())]))
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
                if(!(map[pacman.getY()][ceil(pacman.getX()+pacman.getSpeed())]))
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

Pacman LevelClass::getPacman(){
    return pacman;
}

void LevelClass::checkCollision() {

}