// Ashish Bairwa

#include <bits/stdc++.h>
#define UNASSIGNED 0  
#define N 9 
using namespace std;

// Function to check whether it will be legal to assign num to the given row, col, and 3*3 grid 
bool isSafe(int grid[N][N], int row, int col, int num) {
    int startRow = row - row % 3, startCol = col - col % 3;

    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num || grid[startRow + x / 3][startCol + x % 3] == num) {
            return false;
        }
    }

    return true;
}

// Takes a partially filled-in grid and attempts to assign values to all unassigned locations in such a way to meet the requirements for Sudoku solution (non-duplication across rows, columns, and boxes)
bool solveSudoku(int grid[N][N]) {
    int row, col;
    bool isEmpty = true;
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == UNASSIGNED) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }
 
    // No unassigned position is found, puzzle solved
    if (isEmpty) {
        return true;
    }
 
    // Consider digits 1 to 9
    for (int num = 1; num <= N; num++) {
        // Check if looks promising
        if (isSafe(grid, row, col, num)) {
            // Make tentative assignment
            grid[row][col] = num;
 
            // Return, if success
            if (solveSudoku(grid))
                return true;
 
            // Failure, unmake & try again
            grid[row][col] = UNASSIGNED;
        }
    }
    // This triggers backtracking
    return false;
}
 
// function to print grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}
 
int main() {
    int grid[N][N] = {
        {6, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 9, 8, 7, 0, 0, 0 },
        {0, 0, 0, 0, 0, 0, 0, 3, 0 },

        {3, 0, 0, 0, 2, 0, 0, 0, 9 },
        {0, 9, 0, 0, 0, 0, 0, 0, 0 },
        {0, 0, 0, 0, 3, 0, 0, 0, 0 },

        {0, 0, 0, 0, 9, 0, 0, 0, 0 },
        {0, 0, 0, 0, 0, 0, 8, 0, 0 },
        {0, 0, 0, 0, 0, 0, 0, 0, 6 }
    };
 
    if (solveSudoku(grid) == true)
        printGrid(grid);
    else
        cout << "No Solution exists";
 
    return 0;
}