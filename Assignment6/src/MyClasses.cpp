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

void Entity::setX(double newX) { x = newX; }

void Entity::setY(double newY) { y = newY; }


void Entity::setPos(int newX, int newY)
{
    setX(newX);
    setY(newY);
}

double Entity::getSpeed() { return speed; }

void Entity::setSpeed(float newSpeed) { speed = newSpeed; }

void Entity::Move() {} //needs implementation still

int Entity::getSpawnY() { return spawn_y; }

int Entity::getSpawnX() { return spawn_x; }

void Entity::setSpawn(int newX, int newY)
{
    spawn_x = newX;
    spawn_y = newY;
}

void Entity::die() { return ; }

//----------------------------------------------------Pacman_section---------------------------------------------------------------

Pacman::Pacman(double x, double y, std::string name)
    : Entity(x, y, name), chungus(false), lives(3)
{
    type = PACMAN;
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
        break;
    }
}

int Pacman::eatPowerrup()
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

void Ghost::Behaviour() {} // needs implementation

bool Ghost::getFrightened() { return frightened; }

void Ghost::setFrightened(bool newHuntStatus) { frightened = newHuntStatus; }

void Ghost::setTimeout(int newTimeout) { timeOut = newTimeout; }

int Ghost::getTimeout() { return timeOut; }

void Ghost::die() { setPos(getSpawnX(), getSpawnY()); }
