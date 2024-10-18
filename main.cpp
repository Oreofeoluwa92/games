#include <ncurses.h>
#include "game.h"

int main() {
    MEVENT event;

    initscr();          // Initialize ncurses
    cbreak();           // Disable line buffering
    noecho();           // Don't echo keypresses
    keypad(stdscr, TRUE); // Enable special keys like arrow keys
    mouseinterval(3);   // Set the mouse event delay
    mousemask(ALL_MOUSE_EVENTS, NULL);  // Capture all mouse events

    init_game();  // Initialize the game grid (all dead cells)

    int ch;
    while ((ch = getch()) != 'q') {  // Exit on 'q'
        switch (ch) {
            case KEY_MOUSE:
                if (getmouse(&event) == OK) {
                    if (event.bstate & BUTTON1_PRESSED) {
                        handle_mouse_event(event);  // Toggle cell on mouse click
                    }
                }
                break;
            case 'n':  // Press 'n' to update the generation
                update_generation();  // Update the grid to the next generation
                break;
        }

        // Display the current generation
        display_grid();
    }

    endwin();  // End ncurses mode
    return 0;
}
