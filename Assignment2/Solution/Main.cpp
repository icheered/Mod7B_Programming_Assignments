#include "src/Maze_Tjeerd.h"
#include "src/Maze_Soenke.h"

int main() {

	// Show a prompt for which solution to show
	char which_solution;
	bool running = true;
	while(running){
		which_solution = 'a';
		std::cout << "Which solution do you want to see: (s)oenke's or (t)jeerd's?";
		std::cin >> which_solution;


		if(which_solution == 't'){
			// Show Tjeerd's solution
			Maze_Tjeerd amazingMaze;
			amazingMaze.solveMaze_Tjeerd();
			std::cout << "Solved!" << std::endl;
		}else if(which_solution == 's'){
			// Show Soenke's solution
			Maze test;
			test.solveMaze();
		} else {
			std::cout << "Please enter 's' or 't' to pick which solution to try" << std::endl;
		}
	}



	return 0;
}