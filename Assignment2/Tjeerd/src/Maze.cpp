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
				m_Player.x = j;
				m_Player.y = i;
			}
		}
	}

}

bool Maze::movePlayer(std::array<unsigned int, 2> position, std::array<unsigned int, 2> previous_position)
{
	// Check if maze is solved -> Return True
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	printMaze();

	m_Maze[position[0]][position[1]] = 'o';
	if(finished(position)){
		return true;
	}

	std::array<unsigned int, 2> upPosition = {position[0] - 1, position[1]};
	std::array<unsigned int, 2> leftPosition = {position[0], position[1] - 1};
	std::array<unsigned int, 2> downPosition = {position[0] + 1, position[1] };
	std::array<unsigned int, 2> rightPosition = {position[0], position[1] + 1};

	if(upPosition != previous_position && m_Maze[upPosition[0]][upPosition[1]] != '#' && m_Maze[upPosition[0]][upPosition[1]] != '-'){
		bool correct = movePlayer(upPosition, position);
		if(correct) {
			return true;
		} 
	}
	if(leftPosition != previous_position && m_Maze[leftPosition[0]][leftPosition[1]] != '#' && m_Maze[leftPosition[0]][leftPosition[1]] != '-'){
		bool correct = movePlayer(leftPosition, position);
		if(correct) {
			return true;
		} 
	}
	if(downPosition != previous_position && m_Maze[downPosition[0]][downPosition[1]] != '#' && m_Maze[downPosition[0]][downPosition[1]] != '-'){
		bool correct = movePlayer(downPosition, position);
		if(correct) {
			return true;
		} 
	}
	if(rightPosition != previous_position && m_Maze[rightPosition[0]][rightPosition[1]] != '#' && m_Maze[rightPosition[0]][rightPosition[1]] != '-'){
		bool correct = movePlayer(rightPosition, position);
		if(correct) {
			return true;
		}
	}

	// If the function gets here it means that it hit a dead end
	m_Maze[position[0]][position[1]] = '-';
	return false;
}

void Maze::solveMaze()
{
	movePlayer(m_startingPoint, m_startingPoint);
	printMaze();
}




void Maze::printMaze()
{
	bool valid = false;
	if (m_Player.x < m_Maze.at(0).size() && m_Player.x >= 0 && m_Player.y < m_Maze.size() && m_Player.y >= 0) { m_Maze.at(m_Player.y).at(m_Player.x) = 'X'; valid = true; }
	else std::cout << "Player position invalid" << std::endl;
	for (int i = 0; i < m_Maze.size(); i++) {
		for (int j = 0; j < m_Maze.at(i).size(); j++) {
			std::cout <<" "<<  m_Maze.at(i).at(j);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	if (valid) m_Maze.at(m_Player.y).at(m_Player.x) = '.';
}

void Maze::createMaze()
{ 
	m_startingPoint[0] = 4; m_startingPoint[1] = 11;
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