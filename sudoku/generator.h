#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>

std::vector<int> shuffle(const std::vector<int>& v);
int pattern(int r, int c, int base);
std::vector<std::vector<int>> generate_board();
std::vector<std::vector<int>> makePlayable(std::vector<std::vector<int>> board, const int val);

#endif
