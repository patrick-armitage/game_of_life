/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/17/2016
** Description: GameBoard class stores data about the current state of the Game
** of Life.  It stores a 2D array called "gameboard", its height and width,
** and the starting x / y coordinate a given pattern will be placed upon the
** board.  It defines getters and setters for these attributes, and also the
** createBoard() and destroyBoard() methods, which come in handy for the GoL
** due to the fact that we want to populate the next generation while perserving
** the state of the previous gen.  Thus, we create a new, and destroy the old
** once the new is ready.
*******************************************************************************/

#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

class GameBoard {
 private:
    int height;
    int width;
    int yCoord;
    int xCoord;
    int **gameboard;
 public:
    GameBoard(int height, int width, int yCoord, int xCoord);
    void setHeight(int height);
    int getHeight();
    void setWidth(int width);
    int getWidth();
    void setYCoord(int yCoord);
    int getYCoord();
    void setXCoord(int xCoord);
    int getXCoord();
    int** createBoard();
    void destroyBoard();
    void setBoard(int** board);
    int** getBoard();
};

#endif
