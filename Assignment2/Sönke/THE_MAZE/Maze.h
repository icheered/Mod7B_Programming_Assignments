#pragma once

#include <array>
#include <iostream>

class Maze {
private:
	enum m_Orientation : unsigned int {
		up = 0, left, down, right
	};
	struct Player {
		unsigned int x, y;
		m_Orientation o;
	} m_Player;
	
	std::array<unsigned int, 2> m_startingPoint;
	std::array<std::array<char, 12>, 12> m_Maze;

	//functions needed in order to solve the maze internally
	void assignStandartMaze();
	void turnLeft();
	void turnRight();
	void moveForward();
	void determineStart();

	bool solveMazeRecursive(); //this will be called after solving is startet in order to increase performance
	bool wallFront();
	bool wallRight();
	bool finsihed();
public:
	Maze();
	Maze(std::array<std::array<char, 12>, 12>, std::array<unsigned int, 2>);
	void PrintMaze(); //prints the maze with the current player position in it
	void solveMaze(); //this is the starting point of solving the maze, it prints the movement of the "player" 
};

