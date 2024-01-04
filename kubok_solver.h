#ifndef KUBOK_SOLVER_H
#define KUBOK_SOLVER_H

#include "file_parser.h"
#include <vector>
#include <iostream>

using namespace std;

class KubokSolver
{
private:
    Puzzle puzzle;

    bool is_valid(const vector<vector<int> > &grid, const vector<int> &row_sums, const vector<int> &col_sums);

    bool isInvalidPlace(vector<vector<int> > &grid, const vector<int> &row_sums, const vector<int> &col_sums, int row, int col, int num);

    bool solve(vector<vector<int> > &grid, const vector<int> &row_sums, const vector<int> &col_sums, int row, int col, vector<bool> &used_numbers);

    bool validRowColSum(vector<vector<int> > &grid, const vector<int> &row_sums, const vector<int> &col_sums, int row, int col);

public:
    explicit KubokSolver(const Puzzle &puz);

    bool solve();

    void displayResult();
};

#endif // KUBOK_SOLVER_H
