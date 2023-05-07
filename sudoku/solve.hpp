#ifndef SOLVER
#define SOLVER

#include <vector>

bool validMove(const std::vector<std::vector<int>>& board, int val, int row, int col);
std::vector<int> findEmptyCell(const std::vector<std::vector<int>>& board);
bool solve(std::vector<std::vector<int>>& board);

#endif
