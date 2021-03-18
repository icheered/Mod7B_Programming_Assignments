#include "MyClasses.h"

#include <vector>
#include <math.h>

class LevelClass
{
private:
    Pacman pacman = Pacman(1,1,"pacman");
    std::vector<Ghost> ghosts;
    std::vector<std::vector<int>> map;
    double epsilon = 0.001;

    int dots, score, lives;

    void start();
        // set score 0
        // set dots active
        // set pacman + ghosts location to spawn
        // set lives = 3

    void reset();
        // Set pacman and ghost location to spawn location
        // Wait for user input to start


    void pacmanMurdered();
        // lives--
        // If no lives left
            // game Over
        // else
            // reset()
    void gameOver();
        // Display message
        // Wait for user input to restart

    void ateEnergizer();
        // Make pacman powerful
        // Make ghosts frightened
    void ateDot();
        // score++
        // dots--
        // if dots == 0
            // gameWon()

    void gameWon();
        // Display message
        // Wait for user input to restart
        

public:
    // Constructor
    LevelClass(std::vector<std::vector<int>> startMap);   

    Pacman getPacman();

    void move();
    void handleInput(Direction direc);
        // Check if not moving into a wall
    void checkCollision();
        // If pacman hit a ghost
            // If pacman = big chungus
                // killGhost()
            // Else
                // pacmanMurdered()
        // If pacman hit a fruit / energizer
            // Fruit -> score ++
            // Energizer -> bigChungus()
        // If pacman hit a dot
            // ateDot()
    
};