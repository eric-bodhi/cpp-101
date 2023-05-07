#ifndef GENERATOR_H
#define GENERATOR_H

#include <vector>

std::vector<int> shuffle(const std::vector<int>& v); 
int pattern(int r, int c, int base);
std::vector<std::vector<int>> generate();
std::vector<std::vector<int>> makePlayable(std::vector<std::vector<int>>& board, int val);

#endif
