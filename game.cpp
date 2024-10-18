#include "game.h"

const int Nrow = 20;  // Number of rows
const int Ncol = 40;  // Number of columns
MATRIX grid(Nrow, VEC(Ncol, 0));  // Initialize grid with all dead cells

// Initialize the grid with all dead cells
void init_game() {
    // The grid is already initialized with 0s (dead cells) above
}

// Function to count live neighbors for a cell
int count_live_neighbors(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;  // Skip the cell itself
            int nx = x + i;
            int ny = y + j;
            if (nx >= 0 && ny >= 0 && nx < Nrow && ny < Ncol) {
                count += grid[nx][ny];  // Count live neighbors
            }
        }
    }
    return count;
}

// Function to update the grid for the next generation
void update_generation() {
    MATRIX new_grid(Nrow, VEC(Ncol, 0));  // Create a new grid for the next generation

    for (int i = 0; i < Nrow; i++) {
        for (int j = 0; j < Ncol; j++) {
            int live_neighbors = count_live_neighbors(i, j);

            // Game of Life rules
            if (grid[i][j] == 1) {
                // Any live cell with fewer than two live neighbors dies (underpopulation).
                // Any live cell with two or three live neighbors lives on to the next generation.
                // Any live cell with more than three live neighbors dies (overpopulation).
                if (live_neighbors < 2 || live_neighbors > 3) {
                    new_grid[i][j] = 0;  // Cell dies
                }
                else {
                    new_grid[i][j] = 1;  // Cell survives
                }
            }
            else {
                // Any dead cell with exactly three live neighbors becomes a live cell (reproduction).
                if (live_neighbors == 3) {
                    new_grid[i][j] = 1;  // New cell is born
                }
            }
        }
    }

    grid = new_grid;  // Replace the old grid with the new one
}

// Function to handle mouse input and toggle cells
void handle_mouse_event(MEVENT& event) {
    if (event.y >= 0 && event.y < Nrow && event.x >= 0 && event.x < Ncol) {
        grid[event.y][event.x] = !grid[event.y][event.x];  // Toggle the cell
    }
}

// Function to display the grid
void display_grid() {
    for (int y = 0; y < Nrow; y++) {
        for (int x = 0; x < Ncol; x++) {
            mvprintw(y, x, "%c", grid[y][x] == 1 ? 'X' : ' ');  // Display 'X' for live cells
        }
    }
    refresh();  // Refresh the screen
}
