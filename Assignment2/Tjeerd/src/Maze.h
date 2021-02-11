#pragma once

#include <array>
#include <iostream>

class Maze {
private:
	struct Position {
		unsigned int x, y;
	} m_Player, m_previousPosition;
	
	std::array<unsigned int, 2> m_startingPoint;
	std::array<std::array<char, 12>, 12> m_Maze;

	// Functions needed in order to solve the maze 
	void createMaze();
	void findEntrance();

	// movePlayer Will be called recursively
	bool traverseMaze(std::array<unsigned int, 2> position, std::array<unsigned int, 2> previous_position); 
	bool finished(std::array<unsigned int, 2> position);
public:
	Maze();
	Maze(std::array<std::array<char, 12>, 12>, std::array<unsigned int, 2>);
	void printMaze(); //prints the maze with the current player position in it
	void solveMaze(); //this is the starting point of solving the maze, it prints the movement of the "player" 
};