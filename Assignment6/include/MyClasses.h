#pragma once
#include "GameObjectStruct.h"
#include "string"
#include <math.h>
#include <vector>
#include <iostream>
#include <random>



class Entity : public GameObjectStruct //class extends struct, there should be imlicit conv, structs are fully public
{
//from the GameObjectStruct:
	//pos x,y
	//type
	//direction
private:
  std::string name;
  double speed; 
  int spawn_x, spawn_y;

protected:  // Protected variables can be accessed by inherited classes
  double epsilon;  // Epsilon is used for comparison of doubles
  std::vector<std::vector<int>> *map;
  unsigned int frameCounter; // Used for animation
  unsigned int animationInterval;

public:
  Entity(double x, double y, std::string name);
  std::string getName();
  void setName(std::string newName);
  void setDirectin(Direction direc);
  Direction getDirection();
  void setType(Type newType);
  Type getType();
  void respawn(); //sets the entity back to spawn, animationless
  double getX();
  double getY();
  void setX(double newX);
  void setY(double newY);
  void setPos(int newX, int newY);
  double getSpeed();
  void setSpeed(float newSpeed);
  void setEpsilon(double newEpsilon);
  void setMap(std::vector<std::vector<int>> *newmap);
  bool canMove(Direction direc);  // Checks if entity can move in the current facing direction
  bool canRotate(Direction direc);// Checks if entity can move in the desired facing direction
  virtual void move(); 
  int getSpawnY();
  int getSpawnX();
  void setSpawn(int newX, int newY);
  virtual void die();
};

class Pacman : public Entity
{
  private:
    bool chungus;
    int lives;

  public:
    Pacman(double x, double y, std::string name);
    int eatFruit(Type fruitEaten);
    int eatPowerup();
    void removePowerup();
    bool isChungus();
    void extraLife();
    int getLives();
    bool isDead();
    void die() override;
    void move() override;
};

class Ghost : public Entity
{
  private:
      //corners are (0,0) (0, 26) (27,0) (27,26)
    char lastBehaviour = 's';
    int HomeX, HomeY;
    bool frightened, eaten;
    int timeOut; //subject to change, maybe bool is suited better later on
    //some helper funcs for the behaviour
    int vectorLen(int x1, int y1, int x2, int y2); //since I only need coordinates and comparisons from the vectors they may be rounded to ints
    void determineBestMove(int targetX, int targetY); //finds the best move from ghost position to that field and executes it
    void turnArround(); // turns the ghost arround
    void randomDirection();
  public:
    Ghost(double x, double y, std::string name, Type ghostType);
    void Behaviour(int PacX, int PacY, int BlinkyX, int BlinkyY, Direction PacDir, char Behaviour); //quite complex, still has to be overriden.
    bool getFrightened();
    void setFrightened(bool newHuntStatus);
    void setTimeout(int newTimeout);
    void decrementTimeout();
    int getTimeout();
    void die() override;
    void move() override;
};

