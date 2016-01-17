/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/17/2016
** Description: GameOfLife functions file which defines the functions that were
** prototyped within the GameOfLife header file
*******************************************************************************/

#include "GameBoard.hpp"
#include "Patterns.hpp"
#include "GameOfLife.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/
/*
    Function Name: createStartingShape
    Function Parameters: a GameBoard instance and a pattern selection integer
    What the function does: Using the gameboard instance, finds the starting
                            x and y coordinates, and using the selection int,
                            selects between 1 of 3 starting shapes found in
                            the Patterns functions.  Based on the shape
                            selected, a Pattern function is performed upon
                            the gameboard instance which populates the
                            instance's board with the desired shape.

*/
GameBoard createStartingShape(GameBoard gameboard, int selection) {
    int y_coord = gameboard.getYCoord();
    int x_coord = gameboard.getXCoord();

    if (selection == 1) {
        gameboard = oscillatorPattern(gameboard, y_coord, x_coord);
    } else if (selection == 2) {
        gameboard = gliderPattern(gameboard, y_coord, x_coord);
    } else if (selection == 3) {
        gameboard = gliderCannonPattern(gameboard, y_coord, x_coord);
    }

    return gameboard;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: neighborCount
    Function Parameters: GameBoard instance, width and height indices of cell
    What the function does: finds the height, width and board of the gameboard
                            instance.  Once the provided index values are
                            validated as falling within the range of [0..height]
                            and [0..width], checks the neighboring cells within
                            each of the 8 neighboring indices of the current
                            cell, returning the total number of neighbors
                            for the provided cell

*/
int neighborCount(GameBoard gameboard, int height_index, int width_index) {
    int height  = gameboard.getHeight();
    int width   = gameboard.getWidth();
    int** board = gameboard.getBoard();

    // since all of these vars are set only conditionally, all need default values
    int count, top_index = 0, btm_index = 0, left_index = 0, right_index = 0;
    int top_left = 0, top = 0, top_right = 0;
    int left = 0, right = 0, btm_left = 0, btm = 0, btm_right = 0;
    bool too_high = false, too_low = false, too_left = false, too_right = false;

    // Topmost corners are [0,0] and [0,width]
    // Bottom corners are [height,0] and [height,width]
    // These indices represent the neighbors above, below, to the right & left of current cell
    top_index   = height_index - 1;
    btm_index   = height_index + 1;
    left_index  = width_index - 1;
    right_index = width_index + 1;

    if (top_index < 0)             { too_high = true; }
    if (btm_index > (height - 1))  { too_low = true; }
    if (left_index < 0)            { too_left = true; }
    if (right_index > (width - 1)) { too_right = true; }

    // so long as each of these flags is not true, checks for each neighbor
    if (!too_high && !too_left)  { top_left = board[top_index][left_index]; }
    if (!too_high)               { top = board[top_index][width_index]; }
    if (!too_high && !too_right) { top_right = board[top_index][right_index]; }
    if (!too_left)               { left = board[height_index][left_index]; }
    if (!too_right)              { right = board[height_index][right_index]; }
    if (!too_low && !too_left)   { btm_left = board[btm_index][left_index]; }
    if (!too_low)                { btm = board[btm_index][width_index]; }
    if (!too_low && !too_right)  { btm_right = board[btm_index][right_index]; }

    // since "alive" = 1 and "dead" = 0, we can just sum the indices' values
    // to get the total neighbor count
    count = top_left + top + top_right + left + right + btm_left + btm + btm_right;
    return count;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: determineCellFate
    Function Parameters: cell "state" integer and total number of neighbors
    What the function does: using the provided cell and neighborCount integers,
                            checks to see if cell is "dead" (0) or "alive", then
                            calls checkDeadCellFate and checkLiveCellFate with
                            neighborCount accordingly

*/
int determineCellFate(int cell, int neighborCount) {
    int cellFate;

    if (cell == 0) {
        cellFate = checkDeadCellFate(neighborCount);
    } else {
        cellFate = checkLiveCellFate(neighborCount);
    }

    return cellFate;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: checkDeadCellFate
    Function Parameters: integer number of cell's neighbors
    What the function does: determines whether or not dead cell will come to
                            life in the next generation.  The rules are, if the
                            dead cell has exactly 3 neighbors, it comes to life,
                            otherwise it remains dead

*/
int checkDeadCellFate(int neighborCount) {
    int cellFate;

    if (neighborCount == 3) {
        cellFate = 1;
    } else {
        cellFate = 0;
    }

    return cellFate;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: checkLiveCellFate
    Function Parameters: integer number of cell's neighbors
    What the function does: determines whether or not live cell either remain
                            alive, or die, in the next generation.  THe rules
                            are, if the cell has 1 or less, or more than 3
                            neighbors, the cell dies; otherwise, the cell lives
                            on to the next generation

*/
int checkLiveCellFate(int neighborCount) {
    int cellFate;

    if ((neighborCount < 2) || (neighborCount > 3)) {
        cellFate = 0;
    } else {
        cellFate = 1;
    }

    return cellFate;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: nextGeneration
    Function Parameters: GameBoard instance
    What the function does: finds the height, width and 2D array of GameBoard
                            instance, creates a blank gameboard array, then
                            loops over the existing gameboard array, finding
                            the neighborCount of each cell index, then finding
                            the cell's "fate".  Once finished, the value of the
                            cell is set to its fate, the old gameboard is
                            destroyed, and the new gameboard is set as the
                            gameboard attribute in the GameBoard instance

*/
GameBoard nextGeneration(GameBoard gameboard) {
    int height = gameboard.getHeight();
    int width = gameboard.getWidth();
    int** board = gameboard.getBoard();

    int nbCount, cellFate;
    // create a new blank gameboard to replace to old one once populated
    int** next_gen = gameboard.createBoard();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            nbCount = neighborCount(gameboard, i, j);
            cellFate = determineCellFate(board[i][j], nbCount);

            next_gen[i][j] = cellFate;
        }
    }

    gameboard.destroyBoard();
    gameboard.setBoard(next_gen);
    return gameboard;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: gameStatus
    Function Parameters: GameBoard instance
    What the function does: checks to see whether the gameboard still contains
                            any live cells, returning boolean TRUE if it does
                            and FALSE if it does not.  Using the height, width
                            and gameboard array found from the GameBoard
                            instance, it iterates over each index of the array,
                            continuing to the next one if the value is 0 (e.g.
                            the cell is dead), and setting the "status" flag
                            to TRUE if the cell is alive

*/
bool gameStatus(GameBoard gameboard) {
    int height = gameboard.getHeight();
    int width = gameboard.getWidth();
    int** board = gameboard.getBoard();

    bool status = false;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j] == 0) {
                continue;
            } else {
                status = true;
                break;
            }
        }
    }

    return status;
}
