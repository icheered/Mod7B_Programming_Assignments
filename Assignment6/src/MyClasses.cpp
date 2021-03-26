#include "MyClasses.h"
//------------------------------------------Entity_Section-----------------------------------------------------

Entity::Entity(double x, double y, std::string name)
    : spawn_x(x), spawn_y(y), name(name), speed(0), frameCounter(0)
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
    if(newX < 0.25) { x = newX + 26.75;}
    else if(newX > 26.75) { x = 0.25;}
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
        case UP:case UPA: {
            
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
        case DOWN:case DOWNA: {
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
        case LEFT:case LEFTA: {
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
        case RIGHT:case RIGHTA: {
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
        case UP:case UPA: {
            
            if(diffX < epsilon)
            {
                int xTile;
                if(abs(floor(getX()) - getX()) < abs(ceil(getX()) - getX())) {xTile = floor(getX());}
                else {xTile = ceil(getX());}
                

                if((*map)[floor(getY()-getSpeed())][xTile] != 1)
                {
                    //std::cout << "Rotating UP" << std::endl;
                    std::cout << "3" << std::endl;
                    return true;
                }
                else {
                    return false;
                    std::cout << "Won't rotate, UP blocked" << std::endl;
                }
            } else {return false;}
        } break;
        case DOWN:case DOWNA: {
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
        case LEFT:case LEFTA: {
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
        case RIGHT:case RIGHTA: {
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
    int animationInterval = 2;
    Direction direc = getDirection();
    //std::cout << "x = " << getX() << ", y = " << getY() << std::endl;
    if(canMove(direc)) {
        frameCounter++;
        switch(direc){
            case UP: case UPA: {
                setY(getY()-getSpeed());
                if(frameCounter % animationInterval == 0) 
                {
                    if(direc == UP) { setDirectin(UPA); }
                    else { setDirectin(UP); }
                }
            } break;
            case DOWN: case DOWNA: {
                setY(getY()+getSpeed());
                if(frameCounter % animationInterval == 0) 
                {
                    if(direc == DOWN) { setDirectin(DOWNA); }
                    else { setDirectin(DOWN); }
                }
            } break;
            case LEFT: case LEFTA: {
                setX(getX()-getSpeed());
                if(frameCounter % animationInterval == 0) 
                {
                    if(direc == LEFT) { setDirectin(LEFTA); }
                    else { setDirectin(LEFT);
                }
            } break;
            case RIGHT: case RIGHTA: {
                setX(getX()+getSpeed());
                if(frameCounter % animationInterval == 0) 
                {
                    if(direc == RIGHT) { setDirectin(RIGHTA); }
                    else { setDirectin(RIGHT); }
                }
            } break;
        }
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

int Ghost::vectorLen(int x1, int y1, int x2, int y2)
{
    int len = 0;
    len = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    return len;
}

void Ghost::determineBestMove(int targetX, int targetY) {
    int shortestLength = 1000;
    Direction moveToDir = UP;
    
    //find the best possible move for the ghost to its target, because of the order it also choses the prefered movement if there are same lengths
    if (canRotate(RIGHT) && getDirection() != LEFT && getDirection() != LEFTA) {// rightLen
        
        if (shortestLength >= vectorLen(getX() + 1, getY(), targetX, targetY)) {
            shortestLength = vectorLen(getX() + 1, getY(), targetX, targetY);
            moveToDir = RIGHT;
        }
    }                                                    
    if (canRotate(DOWN) && getDirection() != UP && getDirection() != UPA) {// downLen
        if (shortestLength >= vectorLen(getX(), getY()+1, targetX, targetY)) {
            shortestLength = vectorLen(getX(), getY()+1, targetX, targetY);
            moveToDir = DOWN;
        }
    }                                                
    if (canRotate(LEFT) && getDirection() != RIGHT && getDirection() != RIGHTA) {// leftLen
        if (shortestLength >= vectorLen(getX() - 1, getY(), targetX, targetY)) {
            shortestLength = vectorLen(getX() - 1, getY(), targetX, targetY);
            moveToDir = LEFT;
        }
    }                  

    if (canRotate(UP) && getDirection() != DOWN && getDirection() != DOWNA) {// upLen
        if (shortestLength >= vectorLen(getX(), getY() -1, targetX, targetY)) {
            shortestLength = vectorLen(getX(), getY() -1, targetX, targetY);
            moveToDir = UP;
        }
    }
    setDirectin(moveToDir);
    move();
}
void Ghost::turnArround()
{
    switch (dir) {
    case UP: case UPA:
        setDirectin(DOWN);
        break;
    case DOWN: case DOWNA:
        setDirectin(UP);
        break;
    case LEFT: case LEFTA:
        setDirectin(RIGHT);
        break;
    case RIGHT: case RIGHTA:
        setDirectin(LEFT);
        break;
    default:
        break;
    }
}

void Ghost::randomDirection()
{
    Direction moveToDir;
    std::default_random_engine generator;
    std::vector<Direction> possibleDirs;
    int test = -1;
    std::cout << getDirection() << std::endl;
    if (canRotate(RIGHT) && getDirection() != LEFT && getDirection() != LEFTA) { // rightLen
        possibleDirs.push_back(RIGHT);
        test++;
    }
    if (canRotate(DOWN) && getDirection() != UP && getDirection() != UPA) { // downLen
        possibleDirs.push_back(DOWN);
        test++;
    }
    if (canRotate(LEFT) && getDirection() != RIGHT && getDirection() != RIGHTA) { // leftLen
        possibleDirs.push_back(LEFT);
        test++;
    }
    if (canRotate(UP) && getDirection() != DOWN && getDirection() != DOWNA) { // upLen
        possibleDirs.push_back(UP);
        test++;
    }
    if (!(test < 0)) {
        if (test > 0) {
            std::uniform_int_distribution<int> distribution(0, test);
            moveToDir = possibleDirs.at(distribution(generator));
        } else {
            moveToDir = possibleDirs.at(0);
        }
        setDirectin(moveToDir);
        move();
    }
}
 



Ghost::Ghost(double x, double y, std::string name, Type ghostType)
    : Entity(x, y, name), frightened(false), timeOut(0)
{
    //set target home pos
    switch (ghostType) {
    case INKY:
        HomeX = 27;
        HomeY = 26;
        break;
    case PINKY:
        HomeX = 0;
        HomeY = 0;
        break;
    case CLYDE:
        HomeX = 2;
        HomeY = 26;
        break;
    case BLINKY:
        HomeX = 27;
        HomeY = 0;
        break;
    default:
        HomeX = 10;
        HomeY = 10;
        break;
    }
    setType(ghostType);
}

void Ghost::Behaviour(int PacX, int PacY, int BlinkyX, int BlinkyY, Direction PacDir, char Behaviour) {
    switch (Behaviour) {
    case 's': //scatter
        //ghost tries to move to its home
        determineBestMove(HomeX, HomeY);
        break;
    case 'f': //frightened
        //Ghost turns arround
        if(lastBehaviour != Behaviour) turnArround();
        //Ghost moves random at intersec
        randomDirection();
        break;
    case 'c': //chase
        //Ghost turns arround
        if (lastBehaviour != Behaviour) turnArround();
        switch (type) {
        case BLINKY:
            determineBestMove(PacX, PacY);
            break;
        case PINKY:
            int targetX, targetY;
            switch (PacDir) {
            case UP:case UPA:
                targetY = PacY - 4;
                targetX = PacX - 4;
                break;
            case DOWN: case DOWNA:
                targetY = PacY + 4;
                targetX = PacX;
                break;
            case LEFT: case LEFTA:
                targetY = PacY;
                targetX = PacX - 4;
                break;
            case RIGHT: case RIGHTA:
                targetY = PacY;
                targetX = PacX + 4;
                break;
            default:
                targetX = 0;
                targetY = 0;
                break;
            }
            determineBestMove(targetX, targetY);
            break;
        case INKY:
            //determine target like for pinky with offset of 2
            int pretargetX, pretargetY, finalX, finalY;
            switch (PacDir) {
            case UP: case UPA:
                pretargetY = PacY - 2;
                pretargetX = PacX - 2;
                break;
            case DOWN: case DOWNA:
                pretargetY = PacY + 2;
                pretargetX = PacX;
                break;
            case LEFT: case LEFTA:
                pretargetY = PacY;
                pretargetX = PacX - 2;
                break;
            case RIGHT: case RIGHTA:
                pretargetY = PacY;
                pretargetX = PacX + 2;
                break;
            default:
                pretargetX = 0;
                pretargetY = 0;
                break;
            }
            //vector to Blinky
            int Xoffset, Yoffset;
            Xoffset = BlinkyX - pretargetX;
            Yoffset = BlinkyY - pretargetY;
            //turn vector arround
            finalX = pretargetX - Xoffset;
            finalY = pretargetY - Yoffset;
            //end of vector is final target pos
            determineBestMove(finalX, finalY);
            break;
        case CLYDE:
            int distance;
            //determine distance to 
            distance = vectorLen(getX(), getY(), PacX, PacY);
            if (distance < 8) {
                determineBestMove(HomeX, HomeY);
            } else {
                determineBestMove(PacX, PacY);
            }
            break;
        default:
            break;
        }
        break;
    //case 'e': //eaten
        //ghost moves back to base because it was eaten
      //  break;
    default:
        break;
    }
    lastBehaviour = Behaviour;
} // needs implementation

bool Ghost::getFrightened() { return frightened; }

void Ghost::setFrightened(bool newHuntStatus) 
{ 
    frightened = newHuntStatus;
    if(frightened) { 
        type = SCARED;
        // Change behaviour pattern
        // Change speed or rather not as it brakes the game
    }
    else{
        if(getName() == "blinky") {setType(BLINKY);}
        if(getName() == "pinky") {setType(PINKY);}
        if(getName() == "inky") {setType(INKY);}
        if(getName() == "clyde") {setType(CLYDE);}
    }
}

void Ghost::setTimeout(int newTimeout) { timeOut = newTimeout; }

void Ghost::decrementTimeout()
{
    if(timeOut) { timeOut--; }
    
    if(timeOut == 0) {
        setFrightened(false);
    }
    else if(timeOut % 10 == 0) {
        if(getType() == SCARED) {setType(SCAREDINV);}
        else if(getType() == SCAREDINV) {setType(SCARED);}
    }
}

int Ghost::getTimeout() { return timeOut; }

void Ghost::die() { 
    setPos(getSpawnX(), getSpawnY()); 
    setFrightened(false);
    setSpeed(0.25);
    setTimeout(0);
}

void Ghost::move()
{   
    if(getFrightened()) { decrementTimeout(); }

    unsigned int animationInterval = 3;
    Direction direc = getDirection();
    //std::cout << "x = " << getX() << ", y = " << getY() << std::endl;
    if(canMove(direc)) {
        frameCounter++;
        if(getFrightened() && frameCounter % 2 == 0) { return; }
        switch(direc){
            case UP: case UPA: {
                setY(getY()-getSpeed());
                if(frameCounter % animationInterval == 0) 
                {
                    if(direc == UP) { setDirectin(UPA); }
                    else { setDirectin(UP); }
                }
            } break;
            case DOWN: case DOWNA: {
                setY(getY()+getSpeed());
                if(frameCounter % animationInterval == 0) 
                {
                    if(direc == DOWN) { setDirectin(DOWNA); }
                    else { setDirectin(DOWN); }
                }
            } break;
            case LEFT: case LEFTA: {
                setX(getX()-getSpeed());
                if(frameCounter % animationInterval == 0) 
                {
                    if(direc == LEFT) { setDirectin(LEFTA); }
                    else { setDirectin(LEFT); }
                }
            } break;
            case RIGHT: case RIGHTA: {
                setX(getX()+getSpeed());
                if(frameCounter % animationInterval == 0) 
                {
                    if(direc == RIGHT) { setDirectin(RIGHTA); }
                    else { setDirectin(RIGHT); }
                }
            } break;
        }
    }
}