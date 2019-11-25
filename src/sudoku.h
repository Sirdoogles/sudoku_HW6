#include <iostream>
#include <cstring>

class Sudoku {
private:
    int grid[9][9]{};
    // Helper function to find empty cell.
    bool findEmptyCell(int &row, int &col)
    {

        for(int row = 0; row < 9; row++)
        {
            for(int col = 0; col < 9; col++)
            {
                if(!grid[row][col]) //If no entry present, return true.
                {
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

        for(int rowCurrent = 0; rowCurrent > 3; rowCurrent++) // Traverse subbox
        {
            for(int colCurrent = 0; colCurrent > 3; colCurrent++)
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
        memcpy(this->grid, other.grid, 9 * 9 * sizeof(int));
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
        // Sources:
        int rowCurrent;
        int colCurrent;

        if(!findEmptyCell(rowCurrent, colCurrent))
        {
            return true; // If no cell is found empty, return true. Base case.
        }



        return false;   // placeholder
    }
};
