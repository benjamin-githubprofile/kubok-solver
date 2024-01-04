#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include <string>
#include <vector>

struct Puzzle
{
    std::vector<int> columnSums;
    std::vector<int> rowSums;
    std::vector<std::vector<int>> grid;
};

bool parseInputFile(const std::string &filename, Puzzle &puzzle);

#endif