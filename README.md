# Sudoku Solver

This project is a C++ implementation of a Sudoku solver. The solver takes a partially filled 9x9 Sudoku grid and attempts to fill in the missing numbers to complete the puzzle according to Sudoku rules.

## Getting Started

### Prerequisites

To compile and run this code, you need a C++ compiler that supports C++11 or later.

### Compilation

To compile the code, use the following command:

```sh
g++ -o sudoku_solver sudoku_solver.cpp

```

### Running
```sh
./sudoku_solver
```
## Code Explanation
### Functions
* **isSafe**: This function checks whether it is legal to assign a number to a given row, column, and 3x3 grid
* **solveSudoku**:This function takes a partially filled grid and attempts to assign values to all unassigned locations to meet the requirements for a Sudoku solution (non-duplication across rows, columns, and boxes).

### Constants
* **UNASSIGNED**: Represents an unassigned cell in the Sudoku grid.
* **N**: Represents the size of the Sudoku grid(9x9).

### Usages
1. Define your Sudoku grid in the main function or any other part of the code.
2. Call the solveSudoku function with your grid as the argument.
3. The function will attempt to solve the Sudoku puzzle and modify the grid in place.


### Example
Here is an example of how to use the solver:

```cpp
int main() {
    int grid[N][N] = {
        {6, 0, 2, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 9, 8, 7, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 3, 0},

        {3, 0, 0, 0, 2, 0, 0, 0, 9},
        {0, 9, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 0},

        {0, 0, 0, 0, 9, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 8, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 6}
    };

    if (solveSudoku(grid)) {
        // Print the solved grid
    } else {
        cout << "No solution exists";
    }

    return 0;
}

// output:
solved Sudoku
6 1 2 3 4 5 7 9 8 
4 3 5 9 8 7 1 6 2 
7 8 9 1 6 2 4 3 5 
3 4 1 5 2 8 6 7 9 
2 9 6 4 7 1 5 8 3 
5 7 8 6 3 9 2 1 4 
1 2 4 8 9 6 3 5 7 
9 6 3 7 5 4 8 2 1
8 5 7 2 1 3 9 4 6
