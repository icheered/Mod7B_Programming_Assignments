class LevelClass
{
private:
    // pacman
    // ghosts
    // map

    // int dots = number of empty spaces
    // int score = 0
    // int lives = 3


    // start()
        // set score 0
        // set dots active
        // set pacman + ghosts location to spawn
        // set lives = 3

    // reset()
        // Set pacman and ghost location to spawn location
        // Wait for user input to start


    // pacmanMurdered()
        // lives--
        // If no lives left
            // game Over
        // else
            // reset()
    
    // gameOver()
        // Display message
        // Wait for user input to restart



    // bigChungus()
        // Make pacman powerful
        // Make ghosts frightened

    // ateDot()
        // score++
        // dots--
        // if dots == 0
            // gameWon()
    
    // gameWon()
        // Display message
        // Wait for user input to restart

public:
    // move()
        // Check if not moving into a wall
    // pacmanCollission()
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
            
    
    // 
    
};