/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/17/2016
** Description: Patterns functions file which defines the functions that were
** prototyped within the Patterns header file
*******************************************************************************/

#include "GameBoard.hpp"
#include "Patterns.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/
/*
    Function Name: oscillatorPattern
    Function Parameters: GameBoard instance and the x and y coordinates upon
                         which to place the shape
    What the function does: creates a new gameboard from the GameBoard instance,
                            populating it with the oscillator pattern, then
                            destroying the old board and setting the newly
                            created board as the instance's gameboard array
*/
GameBoard oscillatorPattern(GameBoard gameboard, int y, int x) {
    int p_height = 1;
    int p_width = 3;
    int** pattern = gameboard.createBoard();  // set the pattern to use the gameboard's array

    // 1st row: X X X
    pattern[y + 0][x + 0] = 1; pattern[y + 0][x + 1] = 1; pattern[y + 0][x + 2] = 1;

    gameboard.destroyBoard();
    gameboard.setBoard(pattern);
    return gameboard;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: gliderPattern
    Function Parameters: GameBoard instance and the x and y coordinates upon
                         which to place the shape
    What the function does: creates a new gameboard from the GameBoard instance,
                            populating it with the glider pattern, then
                            destroying the old board and setting the newly
                            created board as the instance's gameboard array
*/
GameBoard gliderPattern(GameBoard gameboard, int y, int x) {
    int p_height = 3;
    int p_width = 3;
    int** pattern = gameboard.createBoard();  // set the pattern to use the gameboard's array
    // validate_coordinates(gameboard, p_height, p_width, y, x);

    // 1st row: _ X _
    pattern[y + 0][x + 0] = 0; pattern[y + 0][x + 1] = 1; pattern[y + 0][x + 2] = 0;
    // 2nd row: _ _ X
    pattern[y + 1][x + 0] = 0; pattern[y + 1][x + 1] = 0; pattern[y + 1][x + 2] = 1;
    // 3rd row: X X X
    pattern[y + 2][x + 0] = 1; pattern[y + 2][x + 1] = 1; pattern[y + 2][x + 2] = 1;

    gameboard.destroyBoard();
    gameboard.setBoard(pattern);
    return gameboard;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: gliderCannonPattern
    Function Parameters: GameBoard instance and the x and y coordinates upon
                         which to place the shape
    What the function does: creates a new gameboard from the GameBoard instance,
                            populating it with the glider cannon` pattern, then
                            destroying the old board and setting the newly
                            created board as the instance's gameboard array
*/
GameBoard gliderCannonPattern(GameBoard gameboard, int y, int x) {
    int p_height = 9;
    int p_width = 36;
    int** p = gameboard.createBoard();  // set the pattern to use the gameboard's array
    // validate_coordinates(gameboard, p_height, p_width, y, x);

    // FULL PATTERN:
    //        1's               10's                20's                30's
    // guide: 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6
    // row 1: _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _ _ _ _
    // row 2: _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ X _ X _ _ _ _ _ _ _ _ _ _ _
    // row 3: _ _ _ _ _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ _ _ X X
    // row 4: _ _ _ _ _ _ _ _ _ _ _ X _ _ _ X _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ _ _ X X
    // row 5: X X _ _ _ _ _ _ _ _ X _ _ _ _ _ X _ _ _ X X _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // row 6: X X _ _ _ _ _ _ _ _ X _ _ _ X _ X X _ _ _ _ X _ X _ _ _ _ _ _ _ _ _ _ _
    // row 7: _ _ _ _ _ _ _ _ _ _ X _ _ _ _ _ X _ _ _ _ _ _ _ X _ _ _ _ _ _ _ _ _ _ _
    // row 8: _ _ _ _ _ _ _ _ _ _ _ X _ _ _ X _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
    // row 9: _ _ _ _ _ _ _ _ _ _ _ _ X X _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _

    p[y + 0][x + 24] = 1;                        // 1/25
    p[y + 1][x + 22] = 1; p[y + 1][x + 24] = 1;  // 2/23, 2/25
    p[y + 2][x + 12] = 1; p[y + 2][x + 13] = 1;  // 3/13, 3/14
    p[y + 2][x + 20] = 1; p[y + 2][x + 21] = 1;  // 3/21, 3/22
    p[y + 2][x + 34] = 1; p[y + 2][x + 35] = 1;  // 3/35, 3/36
    p[y + 3][x + 11] = 1; p[y + 3][x + 15] = 1;  // 4/12, 4/16
    p[y + 3][x + 20] = 1; p[y + 3][x + 21] = 1;  // 4/21, 4/22
    p[y + 3][x + 34] = 1; p[y + 3][x + 35] = 1;  // 4/35, 4/36
    p[y + 4][x + 0] = 1; p[y + 4][x + 1] = 1;    // 5/1, 5/2
    p[y + 4][x + 10] = 1; p[y + 4][x + 16] = 1;  // 5/11, 5/17
    p[y + 4][x + 20] = 1; p[y + 4][x + 21] = 1;  // 5/21, 5/22
    p[y + 5][x + 0] = 1; p[y + 5][x + 1] = 1;    // 6/1, 6/2
    p[y + 5][x + 10] = 1; p[y + 5][x + 14] = 1;  // 6/11, 6/15
    p[y + 5][x + 16] = 1; p[y + 5][x + 17] = 1;  // 6/17, 6/18
    p[y + 5][x + 22] = 1; p[y + 5][x + 24] = 1;  // 6/23, 6/25
    p[y + 6][x + 10] = 1; p[y + 6][x + 16] = 1;  // 7/11, 7/17
    p[y + 6][x + 24] = 1;                        // 7/25
    p[y + 7][x + 11] = 1; p[y + 7][x + 15] = 1;  // 8/12, 8/16
    p[y + 8][x + 12] = 1; p[y + 8][x + 13] = 1;  // 9/13, 9/14

    gameboard.destroyBoard();
    gameboard.setBoard(p);
    return gameboard;
}
