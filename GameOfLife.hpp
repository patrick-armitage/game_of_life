/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/17/2016
** Description: Collection of functions for the Game of Life containing the
** game's rules and core logic.  The functions interface with Patterns.hpp
** functions and GameBoard class, manipulating the results of each game's
** successive generations
*******************************************************************************/

#include <string>
#include "GameBoard.hpp"

#ifndef GAMEOFLIFE_HPP
#define GAMEOFLIFE_HPP

GameBoard createStartingShape(GameBoard gameboard, int selection);
int neighborCount(GameBoard gameboard, int height_index, int width_index);
int determineCellFate(int cell, int neighborCount);
int checkDeadCellFate(int neighborCount);
int checkLiveCellFate(int neighborCount);
GameBoard nextGeneration(GameBoard gameboard);
bool gameStatus(GameBoard gameboard);

#endif
