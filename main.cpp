#include <string>
#include <cstdlib>  // include atoi() function and others

#include "NcursesTools.hpp"
#include "GameBoard.hpp"
#include "Patterns.hpp"
#include "GameOfLife.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    initCurses();

/*----------------------------------------------------------------------------*/
/*
    Section Title: Game Start Menu
    Purpose of the section: Asks the user a series of questions about how they
                            would like to configure the Game of Life, including
                            the shape they want to use, and the x and y
                            coordinates to place that shape on the board.
*/

    // select game shape
    string input1, input2, input3;
    int selection;
    printw("Welcome to the Game of Life!");
    printw("\nPlease select between the following starting shapes:");
    printw("\n[1] Oscillator\n[2] Glider\n[3] Glider Cannon\n");
    input1 = getString();
    selection = atoi(input1.c_str());  // convert input string into integer
    while ((selection < 1) || (selection > 3)) {
        printw("Please try again: ");
        input1 = getString();
        selection = atoi(input1.c_str());
    }

    // minimum and maximum x and y coordinate values for each shape
    int* oscillator = new int[4];
    int* glider = new int[4];
    int* gcannon = new int[4];
    int* curSelection;
    oscillator[0] = 2, oscillator[1] = 18, oscillator[2] = 1, oscillator[3] = 38;
    glider[0] = 1, glider[1] = 16, glider[2] = 1, glider[3] = 37;
    gcannon[0] = 1, gcannon[1] = 11, gcannon[2] = 1, gcannon[3] = 5;

    // choose which shape configuration based on user-selected shape
    if (selection == 1) {
        curSelection = oscillator;
    } else if (selection == 2) {
            curSelection = glider;
    } else {
        curSelection = gcannon;
    }

    // enter the y coordinate value
    int xCoord, yCoord;
    printw("Please input starting y coordinate between %d and %d:", curSelection[0], curSelection[1]);
    input2 = getString();
    yCoord = atoi(input2.c_str());
    while ((yCoord < curSelection[0]) || (yCoord > curSelection[1])) {
        printw("Please try again: ");
        input2 = getString();
        yCoord = atoi(input2.c_str());
    }

    // enter the x coordinate value
    printw("Please input starting x coordinate between %d and %d:", curSelection[2], curSelection[3]);
    input3 = getString();
    xCoord = atoi(input3.c_str());
    while ((xCoord < curSelection[2]) || (xCoord > curSelection[3])) {
        printw("Please try again:");
        input3 = getString();
        xCoord = atoi(input3.c_str());
    }

/*----------------------------------------------------------------------------*/
/*
    Section Title: Game Initialization and Configuration
    Purpose of the section: Using the information gathered in Game Start Menu
                            section, initializes and configures a new game
                            window, placing it in the center of the terminal.
                            After the window is placed, a border is drawn and
                            the screen updated to show the bordered window.
                            A new gameboard is created and configured, and the
                            gameboard is populated with the user's selected
                            shape they chose on game start.  Finally a message
                            is displayed onscreen telling the user how to quit
                            the game
*/

    clear();
    refresh();
    initGameMode();

    // create and position game window
    int startx, starty, width, height;
    height = 22;
    width = 42;
    // Calculating for a center placement of the window
    starty = (LINES - height) / 2;
    startx = (COLS - width) / 2;
    WINDOW *win;
    win = createNewWin(height, width, starty, startx);

    // create and configure gameboard
    GameBoard gameboard(height, width, yCoord, xCoord);
    bool status;
    gameboard = createStartingShape(gameboard, selection);
    int** board = gameboard.getBoard();

    // update screen with gameboard and game shape
    updateScreen(win, board, height, width);
    box(win, 0, 0);
    wrefresh(win);

    printw("Press q to quit");
    refresh();

/*----------------------------------------------------------------------------*/
/*
    Section Title: Game Loop
    Purpose of the section: Runs a loop that continues so long as the user has
                            not pressed the q key, and there are still living
                            cells within the game's current generation
                            (ascertained by the gameStatus() method).  On each
                            loop, the next generation is calculated and the
                            screen is populated with its contents, a sleep
                            timer is set for .2 seconds between each gen,
                            and the screen is cleared out for the next gen

*/

    int pressed_key;
    do {
        // get next generation and update window with its contents
        gameboard = nextGeneration(gameboard);
        board = gameboard.getBoard();
        updateScreen(win, board, height, width);

        // show next generation onscreen
        box(win, 0, 0);
        wrefresh(win);

        status = gameStatus(gameboard);  // find out if any cells are still alive
        usleep(200000);  // wait for 200000 which = 0.2 seconds
        werase(win);  // clear window of contents
    } while (((pressed_key = getch()) != 'q') && (status == true));

/*----------------------------------------------------------------------------*/
/*
    Section Title: End Game
    Purpose of the section: Calls destroyWin with the game window object to
                            delete and remove it from the screen, then endwin
                            function to end the Ncurses session.  Finally,
                            returns 0 from the main() function to end the
                            program's execution
*/

    destroyWin(win);
    endwin();
    return 0;
}
