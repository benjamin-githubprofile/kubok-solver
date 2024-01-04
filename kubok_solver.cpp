#include "kubok_solver.h"
#include "utils.h"
#include <iostream>
#include <iomanip>

KubokSolver::KubokSolver(const Puzzle &puz) : puzzle(puz) {}

bool KubokSolver::is_valid(const vector<vector<int> > &grid, const vector<int> &row_sums, const vector<int> &col_sums) {
    for (int i = 0; i < 4; ++i) {
        int rowSum = grid[i][0] + grid[i][1] + grid[i][2] + grid[i][3];
        int colSum = grid[0][i] + grid[1][i] + grid[2][i] + grid[3][i];
        if (rowSum != row_sums[i] || colSum != col_sums[i]) {
            return false;
        }
    }
    return true;
}

bool KubokSolver::isInvalidPlace(vector<vector<int> > &grid, const vector<int> &row_sums, const vector<int> &col_sums, int row, int col, int num) {
    int rowSum = grid[row][0] + grid[row][1] + grid[row][2] + grid[row][3];
    if (rowSum > row_sums[row]) {
        return true;
    }

    int colSum = grid[0][col] + grid[1][col] + grid[2][col] + grid[3][col];
    if (colSum > col_sums[col]) {
        return true;
    }

    int zeroCnt = 0;
    for (int k = 0; k < 4; k++) {
        if (grid[row][k] == 0) {
            zeroCnt += 1;
        }
    }
    if (zeroCnt == 0 && rowSum < row_sums[row]) {
        return true;
    }

    zeroCnt = 0;
    for (int k = 0; k < 4; k++) {
        if (grid[k][col] == 0) {
            zeroCnt += 1;
        }
    }
    if (zeroCnt == 0 && colSum < col_sums[col]) {
        return true;
    }
    
    return false;
}

bool KubokSolver::validRowColSum(vector<vector<int> > &grid, const vector<int> &row_sums, const vector<int> &col_sums, int row, int col) {
    int rowSum = grid[row][0] + grid[row][1] + grid[row][2] + grid[row][3];
    if (rowSum != row_sums[row]) {
        return false;
    }
    
    return true;
}

// Recursive function to solve the puzzle
bool KubokSolver::solve(vector<vector<int> > &grid, const vector<int> &row_sums, const vector<int> &col_sums, int row, int col, vector<bool> &used_numbers) {
    if (row == 4) {
        return is_valid(grid, row_sums, col_sums);
    }

    if (col == 4) {
        if (validRowColSum(grid, row_sums, col_sums, row, col - 1)) {
            return solve(grid, row_sums, col_sums, row + 1, 0, used_numbers);
        }
        else {
            return false;
        }
    }

    if (grid[row][col] != 0) {
        return solve(grid, row_sums, col_sums, row, col + 1, used_numbers);
    }

    for (int num = 1; num <= 16; ++num) {
        if (used_numbers[num]) continue;
        if (isInvalidPlace(grid, row_sums, col_sums, row, col, num)) {
            continue;
        }

        used_numbers[num] = true;
        grid[row][col] = num;
        if (solve(grid, row_sums, col_sums, row, col + 1, used_numbers)) {
            return true;
        }

        used_numbers[num] = false;
        grid[row][col] = 0;
    }

    return false;
}

bool KubokSolver::solve() {
    vector<bool> used_numbers(17, false);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (puzzle.grid[i][j] != 0) {
                used_numbers[puzzle.grid[i][j]] = true;
            }
        }
    }
    return solve(puzzle.grid, puzzle.rowSums, puzzle.columnSums, 0, 0, used_numbers);
}


void KubokSolver::displayResult() {
    cout << "  ";
    for (int i = 0; i < 4; i++) {
        cout << setw(3) << right << puzzle.columnSums[i];
    }
    cout << endl;
    for (int i = 0; i < 4; i++) {
        cout << setw(2) << puzzle.rowSums[i];
        for (int j = 0; j < 4; j++) {
            cout << setw(3) << right << puzzle.grid[i][j];
        }
        cout << endl;
    }
}