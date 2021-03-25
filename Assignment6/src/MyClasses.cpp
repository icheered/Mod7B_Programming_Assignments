#include "MyClasses.h"
//------------------------------------------Entity_Section-----------------------------------------------------

Entity::Entity(double x, double y, std::string name)
    : spawn_x(x), spawn_y(y), name(name), speed(0)
{
    setX(x);
    setY(y);
    type = ZERO; //for debugging purposes
    setDirectin(UP);
}

std::string Entity::getName() { return name; }

void Entity::setName(std::string newName) { name = newName; }

void Entity::setDirectin(Direction direc) { dir = direc; }

Direction Entity::getDirection() { return dir; }

void Entity::setType(Type newType) { type = newType; }

Type Entity::getType() { return type; }

void Entity::respawn() { setPos((double)getSpawnX(), (double)getSpawnY()); }

double Entity::getX() { return x; }

double Entity::getY() { return y; }

void Entity::setX(double newX) 
{
    if(newX < 0) { x = newX + 28;}
    else if(newX > 28) { x = newX - 28;}
    else { x = newX; }
}

void Entity::setY(double newY) { y = newY; }

bool Entity::canMove(Direction direc) 
{
    double diffX, diffY;
    if(abs(floor(getX()) - getX()) < abs(ceil(getX()) - getX())) {diffX = abs(floor(getX()) - getX());}
    else {diffX = abs(ceil(getX()) - getX());}
    if(abs(floor(getY()) - getY()) < abs(ceil(getY()) - getY())) {diffY = abs(floor(getY()) - getY());}
    else {diffY = abs(ceil(getY()) - getY());}

    switch(direc){
        case UP: {
            
            if(diffX < epsilon){
                int xTile;
                if(abs(floor(getX()) - getX()) < abs(ceil(getX()) - getX())) {xTile = floor(getX());}
                else {xTile = ceil(getX());}

                if((*map)[floor(getY()-getSpeed()+epsilon)][xTile] != 1)
                {
                    return true;
                    //std::cout << "Moving UP!" << std::endl;
                }
                else {
                    return false;
                    //std::cout << "UP is blocked!" << std::endl;
                }
            } else { return false; }
        } break;
        case DOWN: {
            if(diffX < epsilon){
                int xTile;
                if(abs(floor(getX()) - getX()) < abs(ceil(getX()) - getX())) {xTile = floor(getX());}
                else {xTile = ceil(getX());}

                if((*map)[ceil(getY()+getSpeed()-epsilon)][xTile] != 1)
                {
                    return true;
                    //setY(getY()+getSpeed());
                    //std::cout << "Moving DOWN!" << std::endl;
                }
                else {
                    return false;
                    std::cout << "DOWN is blocked!" << std::endl;
                } 
            } else { return false; }
        } break;
        case LEFT: {
            if(diffY < epsilon){
                int yTile;
                if(abs(floor(getY()) - getY()) < abs(ceil(getY()) - getY())) {yTile = floor(getY());}
                else {yTile = ceil(getY());}

                if((*map)[yTile][floor(getX()-getSpeed()+epsilon)] != 1)
                {
                    return true;
                    setX(getX()-getSpeed());
                    //std::cout << "Moving LEFT!" << std::endl;
                }
                else {
                    return false;
                    std::cout << "LEFT is blocked!" << std::endl;
                } 
            } else { return false; }
        } break;
        case RIGHT: {
            if(diffY < epsilon){
                int yTile;
                if(abs(floor(getY()) - getY()) < abs(ceil(getY()) - getY())) {yTile = floor(getY());}
                else {yTile = ceil(getY());}

                if((*map)[yTile][ceil(getX()+getSpeed()-epsilon)] != 1)
                {
                    return true;
                    
                    //std::cout << "Moving RIGHT!" << std::endl;
                }
                else {
                    return false;
                    std::cout << "RIGHT is blocked!" << std::endl;
                }
            } else { return false; }
        } break;
    }
}

bool Entity::canRotate(Direction direc) 
{
    double diffX, diffY;
    if(abs(floor(getX()) - getX()) < abs(ceil(getX()) - getX())) {diffX = abs(floor(getX()) - getX());}
    else {diffX = abs(ceil(getX()) - getX());}
    if(abs(floor(getY()) - getY()) < abs(ceil(getY()) - getY())) {diffY = abs(floor(getY()) - getY());}
    else {diffY = abs(ceil(getY()) - getY());}


    // std::cout << "FloorX: " << abs(floor(getX()) - getX()) << ", CeilX: " << abs(ceil(getX()) - getX()) << std::endl;
    // std::cout << "FloorY: " << abs(floor(getY()) - getY()) << ", CeilY: " << abs(ceil(getY()) - getY()) << std::endl;
    //std::cout << "DiffX: " << diffX << ", DiffY: " << diffY << std::endl;
    switch(direc){
        case 0: {
            if(diffX < epsilon)
            {
                int xTile;
                if(abs(floor(getX()) - getX()) < abs(ceil(getX()) - getX())) {xTile = floor(getX());}
                else {xTile = ceil(getX());}

                if((*map)[floor(getY()-getSpeed())][xTile] != 1)
                {
                    //std::cout << "Rotating UP" << std::endl;
                    return true;
                }
                else {
                    return false;
                    std::cout << "Won't rotate, UP blocked" << std::endl;
                }
            } else {return false;}
        } break;
        case DOWN: {
            if(diffX < epsilon)
            {
                int xTile;
                if(abs(floor(getX()) - getX()) < abs(ceil(getX()) - getX())) {xTile = floor(getX());}
                else {xTile = ceil(getX());}

                if((*map)[ceil(getY()+getSpeed())][xTile] != 1)
                {
                    //std::cout << "Rotating DOWN" << std::endl;
                    return true;
                }
                else {
                    return false;
                    std::cout << "Won't rotate, DOWN blocked" << std::endl;
                }
            } else {return false;}
        } break;
        case LEFT: {
            if(diffY < epsilon)
            {
                int yTile;
                if(abs(floor(getY()) - getY()) < abs(ceil(getY()) - getY())) {yTile = floor(getY());}
                else {yTile = ceil(getY());}

                if((*map)[yTile][floor(getX()-getSpeed())] != 1)
                {
                    //std::cout << "Rotating  LEFT" << std::endl;
                    return true;
                }
                else {
                    return false;
                    std::cout << "Won't rotate, LEFT blocked" << std::endl;
                }
            } else {return false;}
        } break;
        case RIGHT: {
            if(diffY < epsilon)
            {
                int yTile;
                if(abs(floor(getY()) - getY()) < abs(ceil(getY()) - getY())) {yTile = floor(getY());}
                else {yTile = ceil(getY());}

                if((*map)[yTile][ceil(getX()+getSpeed())] != 1)
                {
                    //std::cout << "Rotating RIGHT" << std::endl;
                    return true;
                }
                else {
                    return false;
                    std::cout << "Won't rotate, RIGHT blocked" << std::endl;
                }
            }
            else {return false;}
        } break;
    }
}


void Entity::setPos(int newX, int newY)
{
    setX(newX);
    setY(newY);
}

double Entity::getSpeed() { return speed; }

void Entity::setSpeed(float newSpeed) { speed = newSpeed; }

void Entity::setEpsilon(double newEpsilon) { epsilon = newEpsilon; }

void Entity::setMap(std::vector<std::vector<int>> *newmap) { map = newmap; }

int Entity::getSpawnY() { return spawn_y; }

int Entity::getSpawnX() { return spawn_x; }

void Entity::setSpawn(int newX, int newY)
{
    spawn_x = newX;
    spawn_y = newY;
}

void Entity::die() { return ; }
void Entity::move() { return ; }


//----------------------------------------------------Pacman_section---------------------------------------------------------------

Pacman::Pacman(double x, double y, std::string name)
    : Entity(x, y, name), chungus(false), lives(3)
{
    type = PACMAN;
}

void Pacman::move()
{
    Direction direc = getDirection();
    std::cout << "x = " << getX() << ", y = " << getY() << std::endl;
    if(canMove(direc)) {
        switch(direc){
            case UP: {
                setY(getY()-getSpeed());
            } break;
            case DOWN: {
                setY(getY()+getSpeed());
            } break;
            case LEFT: {
                setX(getX()-getSpeed());
            } break;
            case RIGHT: {
                setX(getX()+getSpeed());
            } break;
        }
    }
}



//void Pacman::eatDot()
//{
//    points += 10;
//    dotsEaten++;
//}

int Pacman::eatFruit(Type fruitEaten)
{
    switch (fruitEaten) {
    case CHERRY:
        return 100;
        break;
    case STRAWBERRY:
        return 300;
        break;
    case ORANGE:
        return 500;
        break;
    case APPLE:
        return 700;
        break;
    case LEMON:
        return 1000;
        break;
    case GRAPES:
        return 2000;
        break;
    default:
        return 0;
        break;
    }
}

int Pacman::eatPowerup()
{
    chungus = true;
    return 50;
}

void Pacman::removePowerup() { chungus = false; }

bool Pacman::isChungus() { return chungus; }

//int Pacman::getDotsEaten() { return dotsEaten; }

void Pacman::extraLife() { lives++; }

int Pacman::getLives() { return lives; }

bool Pacman::isDead()
{
    if (lives < 1)
        return true;
    else {
        return false;
    }
}

void Pacman::die()
{
    lives--;
    setPos(getSpawnX(), getSpawnY());
}

//----------------------------------------------------Ghost_section---------------------------------------------------------------

Ghost::Ghost(double x, double y, std::string name, Type ghostType)
    : Entity(x, y, name), frightened(false), timeOut(0)
{
    setType(ghostType);
}

void Ghost::Behaviour(int PacX, int PacY, Direction PacDir) {
} // needs implementation

bool Ghost::getFrightened() { return frightened; }

void Ghost::setFrightened(bool newHuntStatus) { 
    frightened = newHuntStatus;
    if(frightened) type = SCARED;

    }

void Ghost::setTimeout(int newTimeout) { timeOut = newTimeout; }

int Ghost::getTimeout() { return timeOut; }

void Ghost::die() { 
    type = SCAREDINV;
    setPos(getSpawnX(), getSpawnY()); 
}

void Ghost::move()
{
    std::cout << "GhostMove" << std::endl;
}