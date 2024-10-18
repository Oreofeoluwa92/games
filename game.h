#ifndef GAME_H
#define GAME_H

#include <ncurses.h>
#include <vector>

// Alias for the matrix and vector types
using VEC = std::vector<int>;
using MATRIX = std::vector<VEC>;

// Constants for grid dimensions
extern const int Nrow;
extern const int Ncol;

// Game grid
extern MATRIX grid;

// Function declarations
void init_game();                   // Initialize the grid
void handle_mouse_event(MEVENT &event); // Handle mouse input
void display_grid();                // Display the grid using ncurses
void update_generation();           // Update the grid to the next generation
int count_live_neighbors(int x, int y); // Count live neighbors of a cell

#endif
