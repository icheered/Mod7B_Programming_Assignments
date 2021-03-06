/// \file
/// GameObjectStruct.h

/*
 *  Created on: Jan 30, 2015
 *      Author: frits
 *       Group: TA's
 */
//altered by:
//==============================================================
// Filename : GameObjectStruct.h
// Authors : Tjeerd Bakker and Soenke van Loh
// Version : 1
// License :
// Description : changed the positions from ints to doubles for smoother game experience
//==============================================================

#ifndef SRC_GAMEOBJECTSTRUCT_H
#define SRC_GAMEOBJECTSTRUCT_H

/// These enum values denote the sprite sets available for items on screen.
enum Type {
    PACMAN,
    BLINKY,
    PINKY,
    INKY,
    CLYDE,
    SCARED,
    SCAREDINV,
    CHERRY,
    STRAWBERRY,
    ORANGE,
    LEMON,
    APPLE,
    GRAPES,
    DOT,
    ENERGIZER,
    WALL,
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE
};

/// An enum to denote the direction of an item on screen.
enum Direction { UP, UPA, DOWN, DOWNA, LEFT, LEFTA, RIGHT, RIGHTA };

/// This represents an item that is drawn onto the screen.
struct GameObjectStruct {
    /// x-position of the item.
    double x;
    /// y-position of the item.
    double y;
    /// The appearance of the item (sprite set).
    Type type;
    /// The direction of the item (sprite selection).
    Direction dir;
};

#endif // SRC_GAMEOBJECTSTRUCT_H
