#pragma once

#include <array>
#include <iostream>
#include <chrono>
#include <thread>

class Maze_Tjeerd {
private:
	struct Position {
		unsigned int x, y;
	} m_Player_Tjeerd, m_previousPosition_Tjeerd;
	
	std::array<unsigned int, 2> m_startingPoint_Tjeerd;
	std::array<std::array<char, 12>, 12> m_Maze_Tjeerd;

	// Functions needed in order to solve the maze 
	void createMaze_Tjeerd();
	void findEntrance_Tjeerd();

	// movePlayer Will be called recursively
	bool traverseMaze_Tjeerd(std::array<unsigned int, 2> position_Tjeerd, std::array<unsigned int, 2> previous_position_Tjeerd); 
	bool finished_Tjeerd(std::array<unsigned int, 2> position_Tjeerd);
public:
	Maze_Tjeerd();
	Maze_Tjeerd(std::array<std::array<char, 12>, 12>, std::array<unsigned int, 2>);
	void printMaze_Tjeerd(); //prints the maze with the current player position in it
	void solveMaze_Tjeerd(); //this is the starting point of solving the maze, it prints the movement of the "player" 
};