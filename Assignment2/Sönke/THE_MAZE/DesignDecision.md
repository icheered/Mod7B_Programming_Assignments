# Design Decisions for The Maze

## Class struct

IN the maze we define: rownumber = y , columnnumber = x.
(0,0) is always the top left point, x,y only positiv

One class that holds the Maze and also the "player". The player can go into the same
class as it only holds its x,y position

private members include:
 * startpoint (array(x,y))
 * player (struct(x,y,orientation))
 * maze (two dim arrray 12x12)
 
These informations keep track of the maze and where the player is

As it is only asked to go through one pre defined maze this will just be manually initialized once.

Definition of orientations:

- 0 up (default)
- 1 left
- 2 down 
- 3 right

These will be saved in an enum type for ease of use and readability of code.

Orientations are needed as otherwise a right hand rule cant be applied in order to solve a maze
as it applies to the player and not the overall maze.

functions of class Maze
- void determineStart()
- void solveMaze()
- void printMaze()

voids can be used as they are only class intern in use.

The start has to be determined so we need a function for that which scans through the maze and 
saves the x,y to the player where it finds the 'x' in the maze.

In the end there is a recursive function taking in the maze and all player values in order to solve the maze.
It terminates when it finds a '.' in the maze where either x or y are 0.
It has to change orientation and coordinate of the player.

## solveMaze











