/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/17/2016
** Description: Collection of functions for the Game of Life containing the
** patterns for each of the game's starting shapes.  The functions interface
** with the GameBoard class, populating the GameBoard's array attribute with
** the designated function's contained pattern
*******************************************************************************/

#include "GameBoard.hpp"

#ifndef PATTERNS_HPP
#define PATTERNS_HPP

GameBoard oscillatorPattern(GameBoard gameboard, int y, int x);
GameBoard gliderPattern(GameBoard gameboard, int y, int x);
GameBoard gliderCannonPattern(GameBoard gameboard, int y, int x);

#endif
