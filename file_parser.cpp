#include "file_parser.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

vector<int> split(string data, char pattern) {
    vector<int> res;
    istringstream iss(data);
    string val = "";
    while (getline(iss, val, pattern)) {
        res.push_back(stoi(val));
    }
    return res;
}


bool parseInputFile(const std::string &filename, Puzzle &puzzle) {
    ifstream in(filename);
    if (!in.is_open()) {
        return false;
    }
    string line = "";
    getline(in, line);
    if (line.find("column sums:") == string::npos) {
        return false;
    }
    puzzle.columnSums = split(line.substr(13), ',');
    getline(in, line);
    if (line.find("row sums:") == string::npos) {
        in.close();
        return false;
    }
    puzzle.rowSums = split(line.substr(10), ',');
    getline(in, line);
    while (getline(in, line)) {
        vector<int> row = split(line, ',');
        if (row.size() != 4) {
            return false;
        }
        puzzle.grid.push_back(row);
    }
    in.close();

    if (puzzle.grid.size() != 4 || puzzle.rowSums.size() != 4 || puzzle.columnSums.size() != 4) {
        return false;
    }
    return true;
}
