#include <iostream>
#include <cstring>

class Sudoku {
private:
    int grid[9][9]{};
    // Helper function to find empty cell.
    bool findEmptyCell(int &row, int &col)
    {
        int thisRow;
        int thisCol;

        for(thisRow = 0; thisRow < 9; thisRow++)
        {
            for(thisCol = 0; thisCol < 9; thisCol++)
            {
                if(grid[thisRow][thisCol] == 0)
                {
                    row = thisRow;
                    col = thisCol;
                    return true;
                }
            }
        }
        return false; // Else return false.
    }

    // Helper function to check if value exists in current row.
    bool usedInRow(int row, int target)
    {
        for(int colCurrent = 0; colCurrent < 9; colCurrent++) // Traverse each col, row is static.
        {
            if(grid[row][colCurrent] == target)
            {
                return true;
            }
        }
        return false;
    }

    // Helper function to check if value exists in current col.
    bool usedInCol(int col, int target)
    {
        for(int rowCurrent = 0; rowCurrent < 9; rowCurrent++) // Traverse each row, col is static.
        {
            if(grid[rowCurrent][col] == target)
            {
                return true; // If target found, return true;
            }
        }
        return false; // Else, return false;
    }

    // Helper function to check if value exists in current 3x3 box.
    bool usedInBox(int boxStartRow, int boxStartCol, int target)
    {

        for(int rowCurrent = 0; rowCurrent < 3; rowCurrent++) // Traverse subbox
        {
            for(int colCurrent = 0; colCurrent < 3; colCurrent++)
            {
                if(grid[rowCurrent + boxStartRow][colCurrent + boxStartCol] == target) // If number is found, return true.
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isSafe(int row, int col, int target)
    {
        return(!usedInRow(row, target) && // If not used in row
        !usedInCol(col, target) && // And not in col
        !usedInBox(row - row % 3, col - col % 3, target)); // And not current in boxes.
    }


public:
    explicit Sudoku(int (*grid)[9]) {
        memcpy(this->grid, grid, 9 * 9 * sizeof(int));
    }

    bool operator ==(const int (*otherGrid)[9]) {
        for (int i=0; i<9*9; i++) {
            if (grid[i%3][i/3] != otherGrid[i%3][i/3]) {
                return false;
            }
        }
        return true;
    }

    bool operator ==(const Sudoku & other) {
        for (int i=0; i<9*9; i++) {
            if (grid[i%3][i/3] != other.grid[i%3][i/3]) {
                return false;
            }
        }
        return true;
    }

    int get(int i, int j) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j];
        }

        return -1;
    }

    int set(int i, int j, int val) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j] = val;
        }
        return -1;
    }

    void print() {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                printf(" [%d] ", get(i, j));
                if (j == 8) {
                    printf("\n");
                }
            }
        }
    }

    bool solve() {
        // homework
        // Sources: https://www.sanfoundry.com/cpp-program-solve-sudoku-problem-backtracking/
        int rowCurrent;
        int colCurrent;
        if(!findEmptyCell(rowCurrent, colCurrent))
        {
            return true; // If no cell is found empty, return true. Base case.
        }
        for(int num = 1; num <= 9; num++)
        {
            if(isSafe(rowCurrent, colCurrent, num)) // Checks if number placement is legal.
            {
                grid[rowCurrent][colCurrent] = num;
                if(solve()) // Recusive call.
                {
                    return true;
                }
                grid[rowCurrent][colCurrent] = 0;
            }
        }
        return false;
    }
};
