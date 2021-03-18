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

void Entity::respawn() { setPos((double)getSpawnX(), (double)getSpawnY()); }

int Entity::getX() { return x; }

int Entity::getY() { return y; }

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

Pacman::Pacman(double x, double y, std::string name) : Entity(x,y,name) , chungus(false), lives(3){}

void Pacman::eatDot()
{
    points += 10;
    dotsEaten++;
}

void Pacman::eatFruit(Type fruitEaten)
{
    switch (fruitEaten) {
    case CHERRY:
        points += 100;
        break;
    case STRAWBERRY:
        points += 300;
        break;
    case ORANGE:
        points += 500;
        break;
    case APPLE:
        points += 700;
        break;
    case LEMON:
        points += 1000;
        break;
    case GRAPES:
        points += 2000;
        break;
    default:
        break;
    }
}

void Pacman::eatPowerrup()
{
    points += 50;
    chungus = true;
}

void Pacman::removePowerup() { chungus = false; }

bool Pacman::isChungus() { return chungus; }

int Pacman::getDotsEaten() { return dotsEaten; }

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

Ghost::Ghost(double x, double y, std::string name) : Entity(x,y,name) , frightened(false), timeOut(0) {}

void Ghost::Behaviour() {} // needs implementation

//----------------------------------------------------Ghost_section---------------------------------------------------------------
bool Ghost::getFrightened() { return frightened; }

void Ghost::setFrightened(bool newHuntStatus) { frightened = newHuntStatus; }

void Ghost::setTimeout(int newTimeout) { timeOut = newTimeout; }

int Ghost::getTimeout() { return timeOut; }

void Ghost::die() { setPos(getSpawnX(), getSpawnY()); }
