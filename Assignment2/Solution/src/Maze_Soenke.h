#pragma once

#include <array>
#include <iostream>

//class for storing a maze and solving it.
//The player got an orientation in order to closely simulate how a real person would use the right hand rule.
class Maze {
private:
	enum m_Orientation : unsigned int {
		up = 0, left, down, right
	};
	struct Player {
		unsigned int x, y;
		m_Orientation o;
	} m_Player;
	
	std::array<unsigned int, 2> m_startingPoint; //stores value of initial x in maze
	std::array<std::array<char, 12>, 12> m_Maze; //holds the maze

	//functions needed in order to solve the maze internally
	void assignStandartMaze(); //loads the maze from the assignment into the double array
	void turnLeft();  //change orientation counterclockwise
	void turnRight();  //change orientation clockwise
	void moveForward(); //move one step in direction of orientation
	void determineStart();

	bool solveMazeRecursive(); //this will be called after solving is startet in order to increase performance
	bool wallFront(); //check if wall in direction of orientation one step forward
	bool wallRight(); //check if wall right relative to the player
	bool finsihed(); //true if the player reaches a field at the site of the maze which is not the starting point
public:
	Maze();
	Maze(std::array<std::array<char, 12>, 12>, std::array<unsigned int, 2>);
	void PrintMaze(); //prints the maze with the current player position in it
	void solveMaze(); //this is the starting point of solving the maze
};

