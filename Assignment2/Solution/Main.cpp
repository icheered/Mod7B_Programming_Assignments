#include "src/Maze_Tjeerd.h"
#include "src/Maze_Soenke.h"

int main() {

	bool Soenke = false;
	bool Tjeerd = false;


	if(Soenke){
		Maze test;
		test.solveMaze();
	}
	if(Tjeerd){
		Maze_Tjeerd amazingMaze;
		amazingMaze.solveMaze_Tjeerd();
		std::cout << "Solved!" << std::endl;
	}
	
	if(!Soenke && !Tjeerd) {
		std::cout << "Please set one of the booleans to 'true' in main.cpp" << std::endl;
	}

	return 0;
}