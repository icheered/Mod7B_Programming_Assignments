#pragma once
#include "GameObjectStruct.h"
#include "string"


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
public:
  std::string getName();
  void setName(std::string newName);
  void setDirectin(Direction direc);
  Direction getDirection();
  void respawn(); //sets the entity back to spawn, animationless
  int getX();
  int getY();
  void setX(double newX);
  void setY(double newY);
  void setPos(int newX, int newY);
  double getSpeed();
  void setSpeed(float newSpeed);
  void Move(); //maybe needs more input later on, will be implemented later
  int getSpawnY();
  int getSpawnX();
  void setSpawn(int newX, int newY);
  virtual void die();
  //Type Collision(); //subject to change as tjeerd is designing it, only placeholder propably not called in entity anyway
};

class Pacman : public Entity
{
  private:
    bool chungus;
    int points;
    int dotsEaten;
    int lives;

  public:
    void eatDot(); 
    void eatFruit(Type fruitEaten);
    void eatPowerrup();
    void removePowerup();
    bool isChungus();
    int getDotsEaten();
    void extraLife();
    bool isDead();
    void die() override;
};

class Ghost : public Entity
{
  private:
    bool frightened;
    int timeOut; //subject to change, maybe bool is suited better later on
  public:
    void Behaviour(); //quite complex, still has to be overriden.
    bool getFrightened();
    void setFrightened(bool newHuntStatus);
    void setTimeout(int newTimeout);
    int getTimeout();

};

