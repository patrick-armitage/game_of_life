/*******************************************************************************
** Author: Patrick Armitage
** Date: 01/17/2016
** Description: Code file defining the functions that are declared as
** prototypes within the NcursesTools header file
*******************************************************************************/

#include <string>
#include "NcursesTools.hpp"

using namespace std;

/*----------------------------------------------------------------------------*/
/*
    Function Name: initCurses
    Function Parameters: N/A
    What the function does: initializes Ncurses session in a basic state,
                            setting such commands as getch() to blocking mode
                            which enables user to input GoL configuration
                            before the start of the game
*/
void initCurses() {
    setlocale(LC_ALL, "");
    initscr();
    nocbreak();
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: initGameMode
    Function Parameters: N/A
    What the function does: calls a number of Ncurses configuration commands
                            which allow for Ncurses to run in a non-blocking
                            state, receiving keyboard input but continuing
                            to run the game seemlessly
*/
void initGameMode() {
    raw();
    cbreak();
    noecho();
    nonl();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    curs_set(0);
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: createNewWin
    Function Parameters: height, width, starting x and starting y integers
    What the function does: takes basic information supplied about window
                            size and position within the terminal, and creates
                            and configures new window accordingly.  Height and
                            width are set to 20 and 40 within main.cpp,
                            according to assignment specifications, and startY
                            and startX are calculated based on size of terminal
                            the program is being run in
*/
WINDOW *createNewWin(int height, int width, int startY, int startX) {
    WINDOW *local_win;

    local_win = newwin(height, width, startY, startX);
    box(local_win, 0, 0);  // creates dashes "border" around game window
    wrefresh(local_win);   // refresh() and wrefresh() show screen changes

    return local_win;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: destroyWin
    Function Parameters: game window object
    What the function does: removes the border window, then deletes the
                            supplied window object
*/
void destroyWin(WINDOW *localWin) {
    // calling wborder with all whitespace args removes the dashes border
    wborder(localWin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(localWin);
    delwin(localWin);
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: updateScreen
    Function Parameters: game window, 2D array, and height and width integers
    What the function does: takes the game window and 2D array "gameboard", and
                            adds a block character to the game window screen
                            whenever the current 2D array index has a value of 1
*/
void updateScreen(WINDOW* window, int** two_d_array, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // add 10 to each index, because 2D array is by design larger than
            // the game window, and therefore game window [0][0] index is really
            // 2D array [10][10] index, etc.
            if (two_d_array[i + 10][j + 10] == 1) {
                mvwaddch(window, i, j, ACS_BOARD);  // ACS_BOARD is a block character in Ncurses
            }
        }
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: initCurses
    Function Parameters: N/A
    What the function does:
*/
string getString() {
    string input;
    nocbreak();
    echo();
    int ch = getch();

    while (ch != '\n') {
        input.push_back(ch);
        ch = getch();
    }

    return input;
}
