/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/17/2016
** Description: GameBoard methods file which defines the methods of the
** GameBoard class that were prototyped within the GameBoard header file
*******************************************************************************/

#include <iostream>
#include "GameBoard.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/
/*
    Function Name: GameBoard
    Function Parameters: height, width, y-coordinate and x-coordinate integers
    What the function does: initializes a new instance of the GameBoard class,
                            setting height, width, xCoord and yCoord, and
                            creating and setting a new gameboards
*/
GameBoard::GameBoard(int height, int width, int yCoord, int xCoord) {
    setHeight(height + 20);
    setWidth(width + 20);
    setYCoord(yCoord + 10);
    setXCoord(xCoord + 10);

    // height and width must first be set in order for createBoard() to run
    int** gb = createBoard();
    setBoard(gb);
}

/*----------------------------------------------------------------------------*/
/*
    Function Names: getHeight, setHeight, getWidth, setWidth, getYCoord,
                    setYCoord, getXCoord, setXCoord, getBoard, setBoard
    Functions' Parameters: each setter receives one integer param with the value
                           of the attribute it is going to set
    What the functions do: a series of getters and setters which act as public
                           options to read/write the GameBoard class's private
                           attribute methods
*/
int GameBoard::getHeight() {
    return height;
}

void GameBoard::setHeight(int h) {
    height = h;
}

int GameBoard::getWidth() {
    return width;
}

void GameBoard::setWidth(int w) {
    width = w;
}

int GameBoard::getYCoord() {
    return yCoord;
}

void GameBoard::setYCoord(int y) {
    yCoord = y;
}

int GameBoard::getXCoord() {
    return xCoord;
}

void GameBoard::setXCoord(int x) {
    xCoord = x;
}

int** GameBoard::getBoard() {
    return gameboard;
}

void GameBoard::setBoard(int** board) {
    gameboard = board;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: createBoard
    Function Parameters: N/A
    What the function does: using the GameBoard instance's getHeight and
                            getWidth methods, creates an array of pointers of
                            length "height", then creates a new sub-array in each
                            of the arrays pointers of length "width", setting
                            each sub-array's indices with a value of zero. It
                            then returns this 2D array as a new gameboard
*/
int** GameBoard::createBoard() {
    int height = getHeight();
    int width = getWidth();
    int** board = new int*[height];
    for (int i = 0; i < height; i++) {
        board[i] = new int[width];

        for (int j = 0; j < width; j++) {
            board[i][j] = 0;
        }
    }

    return board;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: destroyBoard
    Function Parameters: N/A
    What the function does: gets the GameBoard instances current "gameboard" 2D
                            array attribute, then calls "delete" on the board.
                            This is useful because whenever a new generation is
                            created in GoL, we want to destroy the old and
                            replace the instance's gameboard attribute with the
                            next generation
*/
void GameBoard::destroyBoard() {
    int** board = getBoard();
    delete board;
}
