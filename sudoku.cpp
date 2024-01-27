#include <bits/stdc++.h>
using namespace std;
#define N 9

class SudokuSolver {
private:
    int grid[N][N];

    bool inCol(int col, int num) {
        for (int row = 0; row < N; row++)
            if (grid[row][col] == num)
                return true;
        return false;
    }

    bool inRow(int row, int num) {
        for (int col = 0; col < N; col++)
            if (grid[row][col] == num)
                return true;
        return false;
    }

    bool inBox(int boxStartRow, int boxStartCol, int num) {
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                if (grid[row + boxStartRow][col + boxStartCol] == num)
                    return true;
        return false;
    }

    bool findEmptyPlace(int &row, int &col) {
        for (row = 0; row < N; row++)
            for (col = 0; col < N; col++)
                if (grid[row][col] == 0) 
                    return true;
        return false;
    }

    bool isValidPlace(int row, int col, int num) {
        return !inRow(row, num) && !inCol(col, num) &&
               !inBox(row - row % 3, col - col % 3, num);
    }

public:
    SudokuSolver(const int initialGrid[N][N]) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                grid[i][j] = initialGrid[i][j];
    }

    void printGrid(const string &message) const {
        cout << message << " Sudoku Board" << endl;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                cout << grid[row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // using backtracking
    bool solve() {
        int row, col;
        if (!findEmptyPlace(row, col))
            return true;

        for (int num = 1; num <= 9; num++) {
            if (isValidPlace(row, col, num)) {
                grid[row][col] = num;

                if (solve())
                    return true;

                grid[row][col] = 0;
            }
        }
        return false;
    }
};

int main() {
    int initialGrid[N][N] = {
        {8, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };

    SudokuSolver sudoku(initialGrid);
    sudoku.printGrid("Initial");
    
    if (sudoku.solve()) sudoku.printGrid("Solved");
    else cout << "No solution exists";

    return 0;
}
