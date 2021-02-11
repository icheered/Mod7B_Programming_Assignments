#include "Maze.h"

#include <chrono>
#include <thread>

Maze::Maze(std::array<std::array<char, 12>, 12> MazeIn, std::array<unsigned int, 2> startIn)
{
	m_Maze = MazeIn;
	m_startingPoint = startIn;
}

Maze::Maze() {
	createMaze();
	findEntrance();
	printMaze();
	m_Player.x = m_startingPoint[1];
	m_Player.y = m_startingPoint[0];
}


bool Maze::finished(std::array<unsigned int, 2> position)
{
	if (position[0] != m_startingPoint[0] && position[1] != m_startingPoint[1]) {
		if (position[0] == 0 || position[0] == 11 || position[1] == 0 || position[1] == 11){
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

void Maze::findEntrance()
{
	for(int i = 0; i < m_Maze.size(); i++) {
		for(int j = 0; j <m_Maze[i].size(); j++) {
			if(m_Maze[i][j] == 'x'){
				std::cout << "Player Starting Position: ";
				std::cout << "(" << j << ", " << i << ")" << std::endl;
				m_startingPoint[0] = i; 
				m_startingPoint[1] = j;
				m_Player.x = j;
				m_Player.y = i;
			}
		}
	}

}

bool Maze::traverseMaze(std::array<unsigned int, 2> position, std::array<unsigned int, 2> previous_position)
{
	// Add a bit of delay for pretty visuals
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	printMaze();


	// Return true if the maze was solved
	m_Maze[position[0]][position[1]] = 'X';
	m_Maze[previous_position[0]][previous_position[1]] = ' ';
	
	if(finished(position)){
		return true;
	}

	// Find the positions if the player were to move in any direction
	std::array<unsigned int, 2> upPosition = {position[0] - 1, position[1]};
	std::array<unsigned int, 2> leftPosition = {position[0], position[1] - 1};
	std::array<unsigned int, 2> downPosition = {position[0] + 1, position[1] };
	std::array<unsigned int, 2> rightPosition = {position[0], position[1] + 1};

	// Check if the position is a valid move
	if(upPosition != previous_position && m_Maze[upPosition[0]][upPosition[1]] != '#' && m_Maze[upPosition[0]][upPosition[1]] != '-'){
		// If it is a valid move, recursively call movePlayer
		bool correct = traverseMaze(upPosition, position);
		if(correct) {
			// If correct == true the maze was solved
			return true;
		} 
	}
	if(leftPosition != previous_position && m_Maze[leftPosition[0]][leftPosition[1]] != '#' && m_Maze[leftPosition[0]][leftPosition[1]] != '-'){
		bool correct = traverseMaze(leftPosition, position);
		if(correct) {
			return true;
		} 
	}
	if(downPosition != previous_position && m_Maze[downPosition[0]][downPosition[1]] != '#' && m_Maze[downPosition[0]][downPosition[1]] != '-'){
		bool correct = traverseMaze(downPosition, position);
		if(correct) {
			return true;
		} 
	}
	if(rightPosition != previous_position && m_Maze[rightPosition[0]][rightPosition[1]] != '#' && m_Maze[rightPosition[0]][rightPosition[1]] != '-'){
		bool correct = traverseMaze(rightPosition, position);
		if(correct) {
			return true;
		}
	}

	// If the method gets to this point it means that there are no valid moves
	// The only possible move is in a previous direction, so the player hit a dead end
	// Print a '-' to show that this path does not lead to victory
	m_Maze[position[0]][position[1]] = '-';
	return false;
}

void Maze::solveMaze()
{
	traverseMaze(m_startingPoint, m_startingPoint);
	printMaze();
}




void Maze::printMaze()
{
	std::cout << std::endl;
	for (int i = 0; i < m_Maze.size(); i++) {
		for (int j = 0; j < m_Maze.at(i).size(); j++) {
			std::cout <<" "<<  m_Maze.at(i).at(j);
		}
		std::cout << std::endl;
	}
}

void Maze::createMaze()
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

	m_Maze = maze;
}