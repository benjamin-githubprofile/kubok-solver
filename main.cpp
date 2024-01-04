#include "file_parser.h"
#include "kubok_solver.h"
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    Puzzle puzzle;

    if (!parseInputFile(filename, puzzle))
    {
        std::cerr << "Error parsing input file." << std::endl;
        return EXIT_FAILURE;
    }

    KubokSolver solver(puzzle);
    if (!solver.solve())
    {
        std::cerr << "No solution found or an error occurred." << std::endl;
        return EXIT_FAILURE;
    }

    solver.displayResult();
    return 0;
}