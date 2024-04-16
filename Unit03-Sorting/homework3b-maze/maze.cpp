#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Grid.h"

using std::string, std::vector, std::cout, std::to_string, std::endl;
using std::ifstream, std::ofstream;


bool findPath(Grid& grid, int row, int col, int level, vector<string>& solution) {
    solution.push_back(to_string(row) + " " + to_string(col) + " " + to_string(level));
    if (row < 0 || row >= grid.height() || col < 0 || col >= grid.width() || level < 0 || level >= grid.depth() || grid.at(row, col, level) == 2 || grid.at(row, col, level) == 0) {
        solution.pop_back();
        return false;
    }
    if(row == grid.height() - 1 && col == grid.width() - 1 && level == grid.depth() - 1) {
        return true;
    }

    grid.at(row, col, level) = 2;

    if (findPath(grid, row - 1, col, level, solution) || findPath(grid, row + 1, col, level, solution) || 
        findPath(grid, row, col - 1, level, solution) || findPath(grid, row, col + 1, level, solution) ||
        findPath(grid, row, col, level - 1, solution) || findPath(grid, row, col, level + 1, solution)) {
            return true;
    } else {
        solution.pop_back();
        return false;
    }
    
}

int main(int argc, char* argv[]) {
    // Write your code here

    string inFileName = argv[1];
    ifstream infile(inFileName);
    string outFileName = argv[2];
    Grid maze;
    infile >> maze;
    infile.close();
    vector<string> solution;
    ofstream outFile(outFileName);

    if (findPath(maze, 0, 0, 0, solution)) {
        outFile << "SOLUTION" << endl;
        for (string sol : solution) {
            outFile << sol << endl;
        }

    } else {
        outFile << "NO SOLUTION" << endl;
    }
    outFile.close();
    
    return 0;
}
