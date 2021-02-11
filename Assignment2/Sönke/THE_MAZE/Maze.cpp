#include "Maze.h"

Maze::Maze(std::array<std::array<char, 12>, 12> MazeIn, std::array<unsigned int, 2> startIn)
{
	m_Maze = MazeIn;
	m_startingPoint = startIn;
}

Maze::Maze() {
	assignStandartMaze();
	m_Player.x = m_startingPoint[1];
	m_Player.y = m_startingPoint[0];
}

void Maze::turnRight()
{
	int temp = m_Player.o;
	if (--temp > -1) m_Player.o = (m_Orientation)temp;
	else m_Player.o = right;
}

void Maze::turnLeft()
{
	int temp = m_Player.o;
	if (++temp < 4) m_Player.o = (m_Orientation)temp;
	else m_Player.o = up;
}

void Maze::moveForward()
{
	switch (m_Player.o) {
	case up:
		m_Player.y--;
		break;
	case left:
		m_Player.x--;
		break;
	case down:
		m_Player.y++;
		break;
	case right:
		m_Player.x++;
		break;
	}
}

bool Maze::wallFront()
{
	switch (m_Player.o) {
	case up:
		if (m_Maze.at(--m_Player.y).at(m_Player.x) == '#') return true;
		break;
	case left:
		if (m_Maze.at(m_Player.y).at(--m_Player.x) == '#') return true;
		break;
	case down:
		if (m_Maze.at(++m_Player.y).at(m_Player.x) == '#') return true;
		break;
	case right:
		if (m_Maze.at(m_Player.y).at(++m_Player.x) == '#') return true;
		break;
	default:
		return false;
	}
	return false;
}

bool Maze::wallRight()
{
	switch (m_Player.o) {
	case left:
		if (m_Maze.at(--m_Player.y).at(m_Player.x) == '#') return true;
		break;
	case down:
		if (m_Maze.at(m_Player.y).at(--m_Player.x) == '#') return true;
		break;
	case right:
		if (m_Maze.at(++m_Player.y).at(m_Player.x) == '#') return true;
		break;
	case up:
		if (m_Maze.at(m_Player.y).at(++m_Player.x) == '#') return true;
		break;
	default:
		return false;
	}
	return false;
}

bool Maze::finsihed()
{
	if (m_Player.x != m_startingPoint[1] && m_Player.y != m_startingPoint[0]) {
		if (m_Player.x == 0 || m_Player.x )
	}
}

void Maze::solveMaze()
{
}

void Maze::solveMazeRecursive()
{
}

void Maze::PrintMaze()
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

void Maze::assignStandartMaze()
{ 
	m_startingPoint[0] = 4; m_startingPoint[1] = 11;
	m_Maze[0][0] = '#';  m_Maze[0][1] = '#';  m_Maze[0][2] = '#';  m_Maze[0][3] = '#';  m_Maze[0][4] = '#';  m_Maze[0][5] = '#';  m_Maze[0][6] = '#';  m_Maze[0][7] = '#';  m_Maze[0][8] = '#';  m_Maze[0][9] = '#';  m_Maze[0][10] = '#'; m_Maze[0][11] = '#';
	m_Maze[1][0] = '#';  m_Maze[1][1] = '.';  m_Maze[1][2] = '.';  m_Maze[1][3] = '.';  m_Maze[1][4] = '#';  m_Maze[1][5] = '.';  m_Maze[1][6] = '.';  m_Maze[1][7] = '.';  m_Maze[1][8] = '.';  m_Maze[1][9] = '.';  m_Maze[1][10] = '.'; m_Maze[1][11] = '#';
	m_Maze[2][0] = '.';  m_Maze[2][1] = '.';  m_Maze[2][2] = '#';  m_Maze[2][3] = '.';  m_Maze[2][4] = '#';  m_Maze[2][5] = '.';  m_Maze[2][6] = '#';  m_Maze[2][7] = '#';  m_Maze[2][8] = '#';  m_Maze[2][9] = '#';  m_Maze[2][10] = '.'; m_Maze[2][11] = '#';
	m_Maze[3][0] = '#';  m_Maze[3][1] = '#';  m_Maze[3][2] = '#';  m_Maze[3][3] = '.';  m_Maze[3][4] = '#';  m_Maze[3][5] = '.';  m_Maze[3][6] = '.';  m_Maze[3][7] = '.';  m_Maze[3][8] = '.';  m_Maze[3][9] = '#';  m_Maze[3][10] = '.'; m_Maze[3][11] = '#';
	m_Maze[4][0] = '#';  m_Maze[4][1] = '.';  m_Maze[4][2] = '.';  m_Maze[4][3] = '.';  m_Maze[4][4] = '.';  m_Maze[4][5] = '#';  m_Maze[4][6] = '#';  m_Maze[4][7] = '#';  m_Maze[4][8] = '.';  m_Maze[4][9] = '#';  m_Maze[4][10] = '.'; m_Maze[4][11] = '.';
	m_Maze[5][0] = '#';  m_Maze[5][1] = '#';  m_Maze[5][2] = '#';  m_Maze[5][3] = '#';  m_Maze[5][4] = '.';  m_Maze[5][5] = '#';  m_Maze[5][6] = '.';  m_Maze[5][7] = '#';  m_Maze[5][8] = '.';  m_Maze[5][9] = '#';  m_Maze[5][10] = '.'; m_Maze[5][11] = '#';
	m_Maze[6][0] = '#';  m_Maze[6][1] = '.';  m_Maze[6][2] = '.';  m_Maze[6][3] = '#';  m_Maze[6][4] = '.';  m_Maze[6][5] = '#';  m_Maze[6][6] = '.';  m_Maze[6][7] = '#';  m_Maze[6][8] = '.';  m_Maze[6][9] = '#';  m_Maze[6][10] = '.'; m_Maze[6][11] = '#';
	m_Maze[7][0] = '#';  m_Maze[7][1] = '#';  m_Maze[7][2] = '.';  m_Maze[7][3] = '#';  m_Maze[7][4] = '.';  m_Maze[7][5] = '#';  m_Maze[7][6] = '.';  m_Maze[7][7] = '#';  m_Maze[7][8] = '.';  m_Maze[7][9] = '#';  m_Maze[7][10] = '.'; m_Maze[7][11] = '#';
	m_Maze[8][0] = '#';  m_Maze[8][1] = '.';  m_Maze[8][2] = '.';  m_Maze[8][3] = '.';  m_Maze[8][4] = '.';  m_Maze[8][5] = '.';  m_Maze[8][6] = '.';  m_Maze[8][7] = '.';  m_Maze[8][8] = '.';  m_Maze[8][9] = '#';  m_Maze[8][10] = '.'; m_Maze[8][11] = '#';
	m_Maze[9][0] = '#';  m_Maze[9][1] = '#';  m_Maze[9][2] = '#';  m_Maze[9][3] = '#';  m_Maze[9][4] = '#';  m_Maze[9][5] = '#';  m_Maze[9][6] = '.';  m_Maze[9][7] = '#';  m_Maze[9][8] = '#';  m_Maze[9][9] = '#';  m_Maze[9][10] = '.';  m_Maze[9][11] = '#';
	m_Maze[10][0] = '#'; m_Maze[10][1] = '.'; m_Maze[10][2] = '.'; m_Maze[10][3] = '.'; m_Maze[10][4] = '.'; m_Maze[10][5] = '.'; m_Maze[10][6] = '.'; m_Maze[10][7] = '.'; m_Maze[10][8] = '.'; m_Maze[10][9] = '.'; m_Maze[10][10] = '.'; m_Maze[10][11] = '#';
	m_Maze[11][0] = '#'; m_Maze[11][1] = '#'; m_Maze[11][2] = '#'; m_Maze[11][3] = '#'; m_Maze[11][4] = '#'; m_Maze[11][5] = '#'; m_Maze[11][6] = '#'; m_Maze[11][7] = '#'; m_Maze[11][8] = '#'; m_Maze[11][9] = '#'; m_Maze[11][10] = '#'; m_Maze[11][11] = '#';
}
