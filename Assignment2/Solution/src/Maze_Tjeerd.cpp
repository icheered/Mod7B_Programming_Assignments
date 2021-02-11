#include "Maze_Tjeerd.h"

#include <chrono>
#include <thread>

Maze_Tjeerd::Maze_Tjeerd(std::array<std::array<char, 12>, 12> MazeIn_Tjeerd, std::array<unsigned int, 2> startIn_Tjeerd)
{
	m_Maze_Tjeerd = MazeIn_Tjeerd;
	m_startingPoint_Tjeerd = startIn_Tjeerd;
}

Maze_Tjeerd::Maze_Tjeerd() {
	createMaze_Tjeerd();
	findEntrance_Tjeerd();
	printMaze_Tjeerd();
	m_Player_Tjeerd.x = m_startingPoint_Tjeerd[1];
	m_Player_Tjeerd.y = m_startingPoint_Tjeerd[0];
}


bool Maze_Tjeerd::finished_Tjeerd(std::array<unsigned int, 2> position_Tjeerd)
{
	if (position_Tjeerd[0] != m_startingPoint_Tjeerd[0] && position_Tjeerd[1] != m_startingPoint_Tjeerd[1]) {
		if (position_Tjeerd[0] == 0 || position_Tjeerd[0] == 11 || position_Tjeerd[1] == 0 || position_Tjeerd[1] == 11){
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

void Maze_Tjeerd::findEntrance_Tjeerd()
{
	for(int i = 0; i < m_Maze_Tjeerd.size(); i++) {
		for(int j = 0; j <m_Maze_Tjeerd[i].size(); j++) {
			if(m_Maze_Tjeerd[i][j] == 'x'){
				std::cout << "Player Starting Position: ";
				std::cout << "(" << j << ", " << i << ")" << std::endl;
				m_startingPoint_Tjeerd[0] = i; 
				m_startingPoint_Tjeerd[1] = j;
				m_Player_Tjeerd.x = j;
				m_Player_Tjeerd.y = i;
			}
		}
	}

}

bool Maze_Tjeerd::traverseMaze_Tjeerd(std::array<unsigned int, 2> position_Tjeerd, std::array<unsigned int, 2> previous_position_Tjeerd)
{
	// Add a bit of delay for pretty visuals
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	printMaze_Tjeerd();


	// Return true if the maze was solved
	m_Maze_Tjeerd[position_Tjeerd[0]][position_Tjeerd[1]] = 'X';
	m_Maze_Tjeerd[previous_position_Tjeerd[0]][previous_position_Tjeerd[1]] = ' ';
	
	if(finished_Tjeerd(position_Tjeerd)){
		return true;
	}

	// Find the positions if the player were to move in any direction
	std::array<unsigned int, 2> upPosition = {position_Tjeerd[0] - 1, position_Tjeerd[1]};
	std::array<unsigned int, 2> leftPosition = {position_Tjeerd[0], position_Tjeerd[1] - 1};
	std::array<unsigned int, 2> downPosition = {position_Tjeerd[0] + 1, position_Tjeerd[1] };
	std::array<unsigned int, 2> rightPosition = {position_Tjeerd[0], position_Tjeerd[1] + 1};

	// Check if the position is a valid move
	if(upPosition != previous_position_Tjeerd && m_Maze_Tjeerd[upPosition[0]][upPosition[1]] != '#' && m_Maze_Tjeerd[upPosition[0]][upPosition[1]] != '-'){
		// If it is a valid move, recursively call movePlayer
		bool correct = traverseMaze_Tjeerd(upPosition, position_Tjeerd);
		if(correct) {
			// If correct == true the maze was solved
			return true;
		} 
	}
	if(leftPosition != previous_position_Tjeerd && m_Maze_Tjeerd[leftPosition[0]][leftPosition[1]] != '#' && m_Maze_Tjeerd[leftPosition[0]][leftPosition[1]] != '-'){
		bool correct = traverseMaze_Tjeerd(leftPosition, position_Tjeerd);
		if(correct) {
			return true;
		} 
	}
	if(downPosition != previous_position_Tjeerd && m_Maze_Tjeerd[downPosition[0]][downPosition[1]] != '#' && m_Maze_Tjeerd[downPosition[0]][downPosition[1]] != '-'){
		bool correct = traverseMaze_Tjeerd(downPosition, position_Tjeerd);
		if(correct) {
			return true;
		} 
	}
	if(rightPosition != previous_position_Tjeerd && m_Maze_Tjeerd[rightPosition[0]][rightPosition[1]] != '#' && m_Maze_Tjeerd[rightPosition[0]][rightPosition[1]] != '-'){
		bool correct = traverseMaze_Tjeerd(rightPosition, position_Tjeerd);
		if(correct) {
			return true;
		}
	}

	// If the method gets to this point it means that there are no valid moves
	// The only possible move is in a previous direction, so the player hit a dead end
	// Print a '-' to show that this path does not lead to victory
	m_Maze_Tjeerd[position_Tjeerd[0]][position_Tjeerd[1]] = '-';
	return false;
}

void Maze_Tjeerd::solveMaze_Tjeerd()
{
	traverseMaze_Tjeerd(m_startingPoint_Tjeerd, m_startingPoint_Tjeerd);
	printMaze_Tjeerd();
}




void Maze_Tjeerd::printMaze_Tjeerd()
{
	std::cout << std::endl;
	for (int i = 0; i < m_Maze_Tjeerd.size(); i++) {
		for (int j = 0; j < m_Maze_Tjeerd.at(i).size(); j++) {
			std::cout <<" "<<  m_Maze_Tjeerd.at(i).at(j);
		}
		std::cout << std::endl;
	}
}

void Maze_Tjeerd::createMaze_Tjeerd()
{
	std::array<std::array<char, 12>, 12> maze;
	maze = {{
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
		{'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
		{'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', 'x'},
		{'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
		{'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
	}};

	m_Maze_Tjeerd = maze;
}